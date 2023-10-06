#include "shell.h"

void _exiT(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        int status = 0;
        if (args[1] != NULL) {
            status = atoi(args[1]);
        }
        printf("%d\n", status);
        exit(status);
    }
}

