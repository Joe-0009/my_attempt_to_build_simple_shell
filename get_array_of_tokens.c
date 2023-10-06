#include "shell.h"

/*
 * get_token - Tokenize a string based on a delimiter
 *
 * @cmd: The input string to tokenize
 * @delim: The delimiter character(s)
 *
 * Returns: An array of strings (tokens) terminated by a NULL pointer
 *          or NULL on failure
 */
char **get_token(char *cmd, char *delim) {
    char *token;
    char **args = malloc(MAX_TOKENS * sizeof(char *));
    unsigned int i = 0;

    if (!args) {
        perror("Malloc in get_token failed\n");
        return NULL;
    }

    token = _strtok(cmd, delim);

    while (token != NULL) {
        args[i] = token;
        i++;

        if (i >= MAX_TOKENS) {
            break;
        }

        token = _strtok(NULL, delim);
    }

    args[i] = NULL;

    return (args);
}
