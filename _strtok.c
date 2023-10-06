#include "shell.h"

/**
 * is_delimiter - Check if a character is a delimiter
 *
 * This function checks if a character is a delimiter by comparing it to the characters
 * in the provided delimiter string.
 *
 * @c: The character to check.
 * @delim: The delimiter character(s) to compare against.
 *
 * Return: 1 if the character is a delimiter, otherwise 0.
 */
int is_delimiter(char c, const char *delim) {
    while (*delim) {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

/**
 * custom_strtok - Custom string tokenizer function
 *
 * This function tokenizes a string based on the provided delimiters.
 * It maintains state between calls using a static variable.
 *
 * @str: The input string to tokenize (or NULL to continue from the last token).
 * @delim: The delimiter character(s).
 *
 * Return: A pointer to the next token found, or NULL if no more tokens are available.
 */
char *_strtok(char *str, const char *delim) {
    static char *next_token = NULL; /* Stores the position of the next token */
    char *token_start; /* Points to the beginning of the current token */

    if (str != NULL) {
        next_token = str; /* Initialize or reset the tokenization */
    }

    if (next_token == NULL || *next_token == '\0') {
        return NULL; /* No more tokens available */
    }

    /* Skip leading delimiters */
    while (is_delimiter(*next_token, delim)) {
        next_token++;
    }

    token_start = next_token; /* Mark the beginning of the token */

    /* Find the end of the token */
    while (*next_token != '\0' && !is_delimiter(*next_token, delim)) {
        next_token++;
    }

    /* If we found a delimiter, replace it with a null terminator */
    if (*next_token != '\0') {
        *next_token = '\0';
        next_token++;
    }

    return token_start; /* Return the beginning of the token */
}

