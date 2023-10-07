#include "shell.h"

char *_getcmd(void)
{
	size_t n = 0;
	size_t len;
	char *buff = NULL;
	ssize_t read_size;

	read_size = _getline(&buff, &n, stdin);
	if (read_size == -1)
	{
		if (feof(stdin))
			printf("\n");
			else
			perror("Error reading input.");
			return (NULL);
	}
	len = _strlen(buff);
	if (buff[len - 1] == '\n')
	{
		buff[len - 1] = '\0';
	}

	return (buff);
}
