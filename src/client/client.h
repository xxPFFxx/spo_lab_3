#ifndef SPO_LAB3_CLIENT_H
#define SPO_LAB3_CLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <memory.h>
#include "ui.h"
#include "clientEvent.h"
#include "../common/protocol.h"
#include "../common/error.h"

struct pthread_args_client {
    int connect_socket;
    struct book **books;
    int *length;
    bool *connect;
    bool *needUpdate;
};

struct pthread_args_event {
    bool *running;
    int *ch;
    bool *needUpdate;
    size_t *args;
};

int start_client(char *ip, long port);

#endif //SPO_LAB3_CLIENT_H
