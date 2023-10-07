#include "shell.h"

/**
 * _unsetenv - Unset an environment variable
 *
 * @name: The name of the environment variable to unset.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name) {
    int i;
    int j;

    if (name == NULL) {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return -1;
    }

    for (i = 0; environ[i] != NULL; i++) {
        char *current_variable = environ[i];

        if (strncmp(current_variable, name, strlen(name)) == 0 && current_variable[strlen(name)] == '=') {
            free(environ[i]);

            for (j = i; environ[j] != NULL; j++) {
                environ[j] = environ[j + 1];
            }

            return 0;
        }
    }

    fprintf(stderr, "Variable not found: %s\n", name);
    return -1;
}

