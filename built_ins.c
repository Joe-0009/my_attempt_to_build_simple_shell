#include "shell.h"

void __exit(char **args) {
    if (_strcmp(args[0], "exit") == 0) {
        int status = 0;
        if (args[1] != NULL) {
            status = _atoi(args[1]);
        }
        printf("%d\n", status);
        exit(status);
    }
}

