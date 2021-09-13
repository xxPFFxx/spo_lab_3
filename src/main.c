#include <errno.h>
#include <string.h>
#include "client/client.h"
#include "server/server.h"
#include "common/utils.h"

#define CLIENT "--client"
#define SERVER "--server"

#define ERROR_MESSAGE_PORT "Port is incorrect. It must be between 1 and 65535\n"
#define MESSAGE_MODE_UNKNOWN "Use command with the first mode required argument '--client' or '--server'. In client mode next args is server address and server port. In server mode next argument is port\n"
#define ERROR_MESSAGE_MODE_CLIENT_ARGS "In client mode there is two required arguments : Server ip address in format X.X.X.X and server port number\n"
#define ERROR_MESSAGE_MODE_SERVER_ARGS "In server mode there is one required argument : server port number\n"
#define ERROR_MESSAGE_IP "Ip is incorrect. It must be in format X.X.X.X and be available\n"


//argc - кол-во аргументов, **argv - передаваемое значение
int main(int argc, char **argv) {
    switch (argc) {
        case 1:
            fprintf(stderr, MESSAGE_MODE_UNKNOWN);
            return EAGAIN; //не блокируем процесс после вызова
        case 2:
            if(strcmp(argv[1], CLIENT) == 0) {
                fprintf(stderr, ERROR_MESSAGE_MODE_CLIENT_ARGS);
            } else if(strcmp(argv[1], SERVER) == 0){
                fprintf(stderr, ERROR_MESSAGE_MODE_SERVER_ARGS);
            } else {
                fprintf(stderr, MESSAGE_MODE_UNKNOWN);
            }
            return EAGAIN;
        case 3:
            if(strcmp(argv[1], CLIENT) == 0) {
                fprintf(stderr, ERROR_MESSAGE_MODE_CLIENT_ARGS);
            } else if(strcmp(argv[1], SERVER) == 0){
                long port = strtol(argv[2], NULL, 10);
                if(port >= 65535 || port < 1) {
                    fprintf(stderr, ERROR_MESSAGE_PORT);
                    return EAGAIN;
                }
                return start_server(port);
            } else {
                fprintf(stderr, MESSAGE_MODE_UNKNOWN);
            }
            return EAGAIN;
        default:
            if(strcmp(argv[1], CLIENT) == 0) {
                long port = strtol(argv[3], NULL, 10);
                if(port >= 65535 || port < 1) {
                    fprintf(stderr, ERROR_MESSAGE_PORT);
                    return EAGAIN;
                }
                if(!isValidIpAddress(argv[2])) {
                    fprintf(stderr, ERROR_MESSAGE_IP);
                    return EAGAIN;
                }
                return start_client(argv[2], port);
            } else if(strcmp(argv[1], SERVER) == 0){
                fprintf(stderr, ERROR_MESSAGE_MODE_SERVER_ARGS);
                return EAGAIN;
            } else {
                fprintf(stderr, MESSAGE_MODE_UNKNOWN);
            }
            return EAGAIN;
    }
}