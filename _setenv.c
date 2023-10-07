#include "shell.h"


/**
 * _setenv - Set or modify an environment variable
 *
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */


int _setenv(const char *name, const char *value) {
    int i;
    char **new_environ;
    int j;
    char *new_variable;

    if (name == NULL || value == NULL) {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return -1;
    }

    for (i = 0; environ[i] != NULL; i++) {
        char *current_variable = environ[i];

        if (strncmp(current_variable, name, strlen(name)) == 0 && current_variable[strlen(name)] == '=') {
            new_variable = (char *)malloc(strlen(name) + strlen(value) + 2);
            if (new_variable == NULL) {
                perror("malloc");
                return -1;
            }
            sprintf(new_variable, "%s=%s", name, value);

            environ[i] = new_variable;
            return 0;
        }
    }

    new_variable = (char *)malloc(strlen(name) + strlen(value) + 2);
    if (new_variable == NULL) {
        perror("malloc");
        return -1;
    }
    sprintf(new_variable, "%s=%s", name, value);

    new_environ = (char **)malloc((environ_size() + 2) * sizeof(char *));
    if (new_environ == NULL) {
        perror("malloc");
        free(new_variable);
        return -1;
    }

    j = 0;
    for (i = 0; environ[i] != NULL; i++) {
        new_environ[j++] = environ[i];
    }
    new_environ[j++] = new_variable;
    new_environ[j] = NULL;

    environ = new_environ;
    return 0;
}



/**
 * environ_size - Get the number of environment variables
 *
 * Return: The number of environment variables.
 */

int environ_size(void) {
    int count = 0;
    while (environ[count] != NULL) {
        count++;
    }
    return count;
}
