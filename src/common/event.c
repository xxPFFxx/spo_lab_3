#include "event.h"

bool tryGetCmd(int ch, cmdFuncImpl *result, command *commandList, size_t commandListSize) {
    *result = NULL;
    if(commandListSize > 1) {
        for (size_t i = 1; *result == NULL && i < commandListSize; i++) {
            command cmd = commandList[i];
            if (ch == cmd.ch) {
                *result = cmd.func;
            }
        }
    }
    return *result != NULL;
}

bool event(int ch, size_t *args, command *commandList, size_t commandListSize) {
    cmdFuncImpl result;
    if (tryGetCmd(ch, &result, commandList, commandListSize)) return result(args);
    else commandList[0].func(args);
    return true;
}