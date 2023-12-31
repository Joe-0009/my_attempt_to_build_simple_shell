#include "shell.h"

/*
 * This function executes a command in a new process.
 *
 * @param path: The path to the executable command.
 * @param args: An array of command arguments including the command itself.
 *
 * @return: Returns the exit status of the executed command, or -1 on failure.
 */
int executor(const char* path, char **args) {
    pid_t pid;           /* Process ID of the child process. */
    int status;          /* Status of the child process. */
    int wait_result;     /* Result of the waitpid function. */

    /* Fork a new process. */
    pid = fork();
    
    if (pid == -1) {
        perror("Fork failed");
        return -1;
    } else if (pid == 0) {
        /* Child process: Execute the command using execvp. */
        if (execvp(path, args) == -1) {
            perror("Execvp failed");
            exit(EXIT_FAILURE);
        }
    } else {
        /* Parent process: Wait for the child process to complete. */
        
        /* Handle EINTR errors when waiting for child process. */
        do {
            wait_result = waitpid(pid, &status, 0);
        } while (wait_result == -1 && errno == EINTR);

        if (wait_result == -1) {
            perror("Waitpid failed");
            return -1;
        }
        
        /* Check if the child process exited normally. */
        if (WIFEXITED(status)) {
            /* Return the exit status of the child process. */
            return WEXITSTATUS(status);
        } else {
            /* Child process did not exit normally. */
            return -1;
        }
    }
    /* Return 0 to indicate success. */
    return 0;
}



int execute_external_command(char *path, char *cmd, char **args) {
    int worked = 1;

    if (path == NULL) {
        printf("not a valid command or path\n");
        free_args(args);
        free(cmd);
        worked = 0;
    } else {
        executor(path, args);
    }

    return worked;
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
    if (strcmp(args[0], "exit") == 0)
    {
        _exiT(args);
        built_in = 1;
    } else if (strcmp(args[0], "env") == 0)
    {
        built_in = _env();
    } else if (strcmp(args[0], "setenv") == 0)
    {
	built_in = _setenv(args[1], args[2]);
    } else if (strcmp(args[0], "unsetenv") == 0)
    {
        built_in = _unsetenv(args[1]);
    }else if (strcmp(args[0], "cd") == 0)
    {
        built_in = _cd(args[1]);
    }else if (strcmp (args[0], "alias") == 0)
    {
	built_in = shell_alias(args + 1, args);
    }
    return built_in;
}
