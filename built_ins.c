#include "shell.h"

/**
* __exit - Exits the shell program with an optional status code.
* @args: An array of strings containing the command and optional status code.
* Return : void.
*/

void __exiT(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		int status = 0;

		if (args[1] != NULL)
		{
			status = _atoi(args[1]);
		}
		printf("%d\n", status);
		exit(status);
	}
}

