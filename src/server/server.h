#ifndef SPO_LAB3_SERVER_H
#define SPO_LAB3_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <stdbool.h>
#include <pthread.h>
#include "../common/protocol.h"
#include "../common/error.h"
#include "../common/book.h"
#include "network.h"

struct pthread_args {
    int connect_socket;
    struct sockaddr_in *remote_address;
    socklen_t *socket_len;
    int *client_number;
};

struct _client_socket {
    int client_socket;
    bool active;
};

int start_server(long port);

#endif //SPO_LAB3_SERVER_H
