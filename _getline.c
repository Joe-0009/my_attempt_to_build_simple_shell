#include "shell.h"

#define INITIAL_BUFFER_SIZE 128

/*
 * _getline - Custom implementation of getline to read a line from a file stream.
 *
 * @lineptr: Pointer to a buffer where the line will be stored.
 * @n: Pointer to the buffer size.
 * @stream: File stream from which to read the line.
 *
 * Returns: The number of characters read, or -1 on error.
 */


ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
    static ssize_t input;
    ssize_t read_count;
    char *buffer;
    char c = 'c';
    ssize_t read_return;

    if (input == 0)
        fflush(stream);
    else
        return (-1);
    input = 0;

    buffer = malloc(sizeof(char) * INITIAL_BUFFER_SIZE);
    if (!buffer)
        return (-1);

    while (c != '\n') {
        read_return = read(STDIN_FILENO, &c, 1);
        if (read_return == -1 || (read_return == 0 && input == 0)) {
            free(buffer);
            return (-1);
        }
        if (read_return == 0 && input != 0) {
            input++;
            break;
        }

        if (input >= INITIAL_BUFFER_SIZE) {
            buffer = _realloc(buffer, input, input + 1);
            if (!buffer) {
                perror("Memory reallocation error");
                return -1;
            }
        }

        buffer[input] = c;
        input++;
    }

    buffer[input] = '\0';

    *lineptr = buffer;

    read_count = input;
    if (read_return != 0)
        input = 0;

    *n = read_count - 1;

    return (read_count);
}
