#include "shell.h"
char *_getenv(const char *name) {
    int i;
    char *entry;

    if (name == NULL) {
        fprintf(stderr, "custom_getenv: Invalid input\n");
        return NULL;
    }

    for (i = 0; environ[i] != NULL; i++) {
        entry = environ[i];
        if (strncmp(entry, name, strlen(name)) == 0 && entry[strlen(name)] == '=') {
            return entry + strlen(name) + 1;
        }
    }

    return NULL;
}
