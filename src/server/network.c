#include "network.h"
#include "../common/error.h"
#include "../common/protocol.h"


int socket_open(int *connect_socket) {
    printf(MESSAGE_SOCKET_OPEN);
    //Инициализация сокета
    *connect_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (connect_socket < 0) {
        printf(ERROR_MESSAGE_SOCKET_OPEN);
        perror(ERROR_MESSAGE_SOCKET_OPEN);
        return ERROR_SERVER_SOCKET_OPEN;
    }
    printf(MESSAGE_DONE);
    return SUCCESS;
}

int socket_set_name(const int *connect_socket, int *reuse) {
    printf(MESSAGE_SOCKET_SET_NAME);
    // Устанавливаем опции сокета

    // connect_socket - сокет десриптор
    // SOL_SOCKET уровень - библиотека сокетов
    // SO_REUSEADDR - разрешает повторное использование локальных адресов
    // reuse -  булево значение, для включения посылки
    // последний аргумент - размер reuse
    if (setsockopt(*connect_socket, SOL_SOCKET, SO_REUSEADDR, reuse, sizeof(int)) == -1) {
        printf(ERROR_MESSAGE_SOCKET_SET_NAME);
        perror(ERROR_MESSAGE_SOCKET_SET_NAME);
        return ERROR_SERVER_SOCKET_SET_NAME;
    }
    printf(MESSAGE_DONE);
    return SUCCESS;
}

//Присваивание сокету имени, для обеспечения соедениия с клиентом
int socket_bind(const int *connect_socket, struct sockaddr_in *server_address) {
    printf(MESSAGE_SOCKET_BIND);
    // Связываем сокет с локальным адресом протокола

    // connect_socket - сокет дескриптор
    // struct server_address - указатель на структуру имени сокета
    if (bind(*connect_socket, (struct sockaddr *) server_address, sizeof(struct sockaddr_in)) == -1) {
        printf(ERROR_MESSAGE_SOCKET_BIND);
        perror(ERROR_MESSAGE_SOCKET_BIND);
        return ERROR_SERVER_SOCKET_BIND;
    }
    printf(MESSAGE_DONE);
    return SUCCESS;
}

int socket_listen(const int *connect_socket, int max_client) {
    printf(MESSAGE_SOCKET_LISTEN);
    // Привязываемый сокет к принятию входящих соединений

    // connect_socket - дескриптор сокета
    // max_client - число соединений
    if (listen(*connect_socket, max_client) == -1) {
        printf(ERROR_MESSAGE_SOCKET_LISTEN);
        perror(ERROR_MESSAGE_SOCKET_LISTEN);
        return ERROR_SERVER_SOCKET_LISTEN;
    }
    printf(MESSAGE_DONE);
    return SUCCESS;
}


// Инициализация соединения
int init_connect(int *connect_socket, struct sockaddr_in *server_address, int *reuse, long port, int max_client) {
    int errno = SUCCESS;

    errno = socket_open(connect_socket);
    if (errno != SUCCESS) return errno;

    server_address->sin_family = AF_INET;
    server_address->sin_port = htons(port);
    server_address->sin_addr.s_addr = htonl(INADDR_ANY);

    errno = socket_set_name(connect_socket, reuse);
    if (errno != SUCCESS) return errno;

    errno = socket_bind(connect_socket, server_address);
    if (errno != SUCCESS) return errno;

    errno = socket_listen(connect_socket, max_client);
    if (errno != SUCCESS) return errno;

    return SUCCESS;
}