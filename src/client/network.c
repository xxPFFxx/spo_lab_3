#include "network.h"

//Подключения клиента


int open_socket(int *client_socket) {
    printf(MESSAGE_SOCKET_OPEN);

    // socket - создаём конечную точку соединения и возвращает файловый дескриптор.

    //PF_INET - указываим семейство протоколов создаваемого сокета.
    //SOCK_STREAM - надёжная потокоориентированная служба (сервис) или потоковый сокет
    // Указываем протокол
    *client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*client_socket < 0) {
        printf(ERROR_MESSAGE_SOCKET_OPEN);
        perror(ERROR_MESSAGE_SOCKET_OPEN);
        return ERROR_CLIENT_OPEN_SOCKET;
    }
    printf(MESSAGE_DONE);
    return SUCCESS;
}

int socket_connect(const int *client_socket, struct sockaddr_in *server_address) {
    printf(MESSAGE_SOCKET_CONNECT);
    // connect - устанавливаем соединение с сервером.

    if (connect(*client_socket, (struct sockaddr *) server_address, sizeof(struct sockaddr_in)) == -1) {
        printf(ERROR_MESSAGE_SOCKET_CONNECT);
        perror(ERROR_MESSAGE_SOCKET_CONNECT);
        return ERROR_CLIENT_CONNECT;
    }
    printf(MESSAGE_DONE);
    return SUCCESS;
}

//Проверка подключения клиента
int check_connect(const int *client_socket) {
    struct command_frame config_frame;
    unpack_command(*client_socket, &config_frame);
    if (!((config_frame.command == SERVER_FULL) && (config_frame.parameter == 0))) {
        close(*client_socket);
        return ERROR_CLIENT_CONNECT_SERVER;
    }
    return SUCCESS;
}

// Подключаем клиента
int connect_server(char *ip, long port, int *client_socket) {
    int err = SUCCESS;

    err = open_socket(client_socket);
    if (err != SUCCESS) return err;

    struct sockaddr_in server_address = {.sin_family = AF_INET, .sin_port = htons(port)};
    struct in_addr serv_address;
    if (inet_aton(ip, &serv_address) != 0) {
        server_address.sin_addr = serv_address;
    } else {
        server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    }

    err = socket_connect(client_socket, &server_address);
    if (err != SUCCESS) return err;

    err = check_connect(client_socket);
    if (err != SUCCESS) return err;

}
// Отключения клиента
void client_quit(const int *client_socket) {
    struct command_frame configFrame = {.command = CLIENT_QUIT, .parameter = 0};
    send_command(*client_socket, &configFrame);
    printf(MESSAGE_SOCKET_CLOSE);
    shutdown(*client_socket, SHUT_RDWR);
    close(*client_socket);
    printf(MESSAGE_DONE);
}


void get_books_net(const int *client_socket, struct book ***books, int *length) {
    struct command_frame configFrame = {.command = GET_ALL_BOOK, .parameter = 0};
    int old_length = *length;
    (*length) = 0;
    send_command(*client_socket, &configFrame);
    struct book_command_frame bf;
    while (true) {
        unpack_book_command(*client_socket, &bf);
        if (bf.command == SEND_BOOK_EOF) {
            (*books)[(*length)] = NULL;
            break;
        } else {
            if ((*books)[(*length)] == NULL) {
                (*books)[(*length)] = calloc(1, sizeof(struct book));
            }
            memcpy((*books)[(*length)], &(bf.book), sizeof(struct book));
            (*length)++;
            if (old_length <= *length)
                (*books) = realloc((*books), ((*length) + 1) * sizeof(struct book *));
        }
    }
}

void update_book(const int *client_socket, struct book *book) {
    struct command_frame configFrame = {.command = CLIENT_UPDATE_BOOK, .parameter = 0};
    struct book_command_frame bookFrame = {.command = CLIENT_UPDATE_BOOK, .book = *book};

    send_command(*client_socket, &configFrame);
    send_book_command(*client_socket, &bookFrame);
}