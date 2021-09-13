#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "protocol.h"
#include "error.h"

int send_command(int socket, struct command_frame *frame){
    unsigned char frame_array[2];
    frame_array[0] = frame->command;
    frame_array[1] = frame->parameter;

    if ((write(socket, frame_array, 2)) == -1) {
        perror("\nError: 'send message'");
        exit(1);
    }
    return 0;
}

int unpack_command(int socket, struct command_frame *frame) {
    unsigned char frame_array[2];

    long err = read(socket, frame_array, 2);
    if(err == -1) {
        fprintf(stderr, "Error read in unpack_command");
        exit(1);
    }
    frame->command = frame_array[0];
    frame->parameter = frame_array[1];
    return 0;
}

int send_book_command(int socket, struct book_command_frame *frame) {
    if(send(socket, frame, sizeof(struct book_command_frame), 0) == -1) {
        perror("\nError: 'send message'");
        return ERROR_SERVER_SEND_BOOK;
    }
    return 0;
}

int unpack_book_command(int socket, struct book_command_frame *frame) {
    if(read(socket, frame, sizeof(struct book_command_frame)) < 1) {
        fprintf(stderr, "Error read in unpack_command");
        exit(1);
    }
    return 0;
}
