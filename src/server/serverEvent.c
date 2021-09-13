#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include "server.h"
#include "serverEvent.h"

bool com_default(size_t *args) {
    size_t i = args[0];
    struct _client_socket *client_sockets = (struct _client_socket *) args[1];
    fprintf(stderr, "Client #%zu: Unknown packet\n", i);
    close(client_sockets[i].client_socket);
    client_sockets[i].active = false;
    return true;
}

//Передача всех книг
bool com_get_all_book(size_t *args) {
    size_t i = args[0];
    struct _client_socket *client_sockets = (struct _client_socket *) args[1];
    size_t length_book = args[2];
    struct book **books = (struct book **) args[3];
    printf("Client #%zu: Get All\n", i);
    struct book_command_frame bookFrame;
    for (int lbook = 0; lbook < length_book; lbook++) {
        if (books[lbook]) {
            bookFrame.book = *(books[lbook]);
            bookFrame.command = SEND_BOOK;
        } else {
            bookFrame.book = (struct book) {};
            bookFrame.command = SEND_BOOK_EOF;
        }
        send_book_command(client_sockets[i].client_socket, &bookFrame);
    }
    return false;
}

//Отключение клиента
bool com_client_quit(size_t *args) {
    size_t i = args[0];
    struct _client_socket *client_sockets = (struct _client_socket *) args[1];
    printf("Client #%zu: Quit\n", i);
    close(client_sockets[i].client_socket);
    client_sockets[i].active = false;
    return true;
}

//Упаковка сообщения
void packAll(const int *client_number, struct _client_socket *client_sockets, struct command_frame *configFrame) {
    //Передаем все сообщения от клиента пока он активен
    for(int i = 0; i < *client_number; i++) {
        if(client_sockets[i].client_socket > 0 && client_sockets[i].active) {
            send_command(client_sockets[i].client_socket, configFrame);
        }
    }
}

//Обновление книги клиентом
bool com_client_update_book(size_t *args) {
    size_t i = args[0];
    struct _client_socket *client_sockets = (struct _client_socket *) args[1];
    size_t length_book = args[2];
    struct book **books = (struct book **) args[3];
    int *client_number = (int *) args[4];
    printf("Client #%zu: update Book\n", i);
    struct book_command_frame bookFrameUpdate;
    unpack_book_command(client_sockets[i].client_socket, &bookFrameUpdate);
    for (int book_index = 0; book_index < length_book; book_index++) {
        if (books[book_index]->bookID == bookFrameUpdate.book.bookID) {
            if (books[book_index]->available < bookFrameUpdate.book.available){
                printf("Client #%zu has returned %s\n", i, bookFrameUpdate.book.title);
            }
            if (books[book_index]->available > bookFrameUpdate.book.available){
                printf("Client #%zu has taken %s\n", i, bookFrameUpdate.book.title);
            }
            memcpy(books[book_index], &(bookFrameUpdate.book), sizeof(struct book));
            break;
        }
    }
    struct command_frame configFrame;
    configFrame.command = SEND_UPDATE_INFO;
    packAll(client_number, client_sockets, &configFrame);
    return true;
}

command knownCommandServer[] = {
        {DEFAULT_EVENT,      &com_default},
        {GET_ALL_BOOK,       &com_get_all_book},
        {CLIENT_QUIT,        &com_client_quit},
        {CLIENT_UPDATE_BOOK, &com_client_update_book},
};

bool serverHandler(int ch, size_t *args) {
    return event(ch, args, knownCommandServer, CI_SIZE(knownCommandServer));
}