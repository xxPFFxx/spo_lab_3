#ifndef SPO_LAB3_PROTOCOL_H
#define SPO_LAB3_PROTOCOL_H

#include "book.h"

//#define SERVER_TCP_PORT 1404
#define MAX_CLIENT_NUMBER 8

/// Протокол связи и сообщения
#ifndef __USE_PROTOCOL
#define SERVER_FULL  1  // Сервер передаёт клиенту информацию о удачном подключении или причину отказа
#define GET_ALL_BOOK 2
#define SEND_BOOK_EOF 3
#define SEND_BOOK 4
#define CLIENT_QUIT 5
#define CLIENT_UPDATE_BOOK 6
#define SEND_UPDATE_INFO 7
#define SERVER_QUIT 8
#endif

#define MESSAGE_SOCKET_OPEN "Opening a socket..."
#define MESSAGE_SOCKET_SET_NAME "Setting options on socket..."
#define MESSAGE_SOCKET_BIND "Binding a name to a socket..."
#define MESSAGE_SOCKET_LISTEN "Listening for a connections..."
#define MESSAGE_SOCKET_CONNECT "Connecting to a server..."
#define MESSAGE_SOCKET_CLOSE "Closing a socket..."
#define MESSAGE_DONE "done\n"


/// Стандартный кадр (2 байта)
struct command_frame {
    unsigned char command;
    unsigned char parameter;
};

struct book_command_frame {
    unsigned char command;
    struct book book;
};

/// Запаковка стандартного кадра и отправка
int send_command(int socket, struct command_frame *frame);
/// Распаковка стандартного кадра
int unpack_command(int socket, struct command_frame *frame);

int send_book_command(int socket, struct book_command_frame *frame);
int unpack_book_command(int socket, struct book_command_frame *frame);

#endif //SPO_LAB3_PROTOCOL_H
