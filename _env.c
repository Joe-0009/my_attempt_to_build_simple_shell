#include "shell.h"

/*
 * _env -function  Print the current environment variables
 *
 * @args: Array of arguments (unused)
 *
 * Return: Always returns 0
 */
int _env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	return (0);
}
