#include "shell.h"

/*
 * This function executes a command in a new process.
 *
 * @param path: The path to the executable command.
 * @param args: An array of command arguments including the command itself.
 *
 * @return: Returns the exit status of the executed command, or -1 on failure.
 */
int executor(const char *path, char **args)
{
	pid_t pid;           /* Process ID of the child process. */
	int status;          /* Status of the child process. */
	int wait_result;     /* Result of the waitpid function. */

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		return (-1);
	} else if (pid == 0)
	{
		if (execvp(path, args) == -1)
		{
			perror("Execvp failed");
			exit(EXIT_FAILURE);
		}
	} else
	{
		do {
			wait_result = waitpid(pid, &status, 0);
		} while (wait_result == -1 && errno == EINTR);
		if (wait_result == -1)
		{
			perror("Waitpid failed");
			return (-1);
		}
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		} else
		{
			return (-1);
		}
	}
	return (0);
}



int execute_external_command(char *path, char *cmd, char **args)
{
	int worked = 1;

	if (path == NULL)
	{
		printf("not a valid command or path\n");
		free_args(args);
		free(cmd);
		worked = 0;
	} else
	{
		executor(path, args);
	}

	return (worked);
}

int execute_builtin_commands(char **args)
{
	int built_in = 0;

	if (strcmp(args[0], "exit") == 0)
	{
		_exiT(args);
		built_in = 1;
	}
	if (strcmp(args[0], "env") == 0)
	{
		built_in = _env();
	}
	return (built_in);
}
