#include "shell.h"


/*
 * is_builtin_command - Check if a command is a built-in command
 *
 * @command: The command to check
 *
 * Return: 1 if it's a built-in command, 0 otherwise
 */
int is_builtin_command(const char *command) {
    /* List of built-in commands */
    const char *builtin_commands[] = {"exit", "setenv", "env", "unsetenv", "cd"};
    size_t num_builtin_commands = sizeof(builtin_commands) / sizeof(builtin_commands[0]);
    size_t i;
    
    for (i = 0; i < num_builtin_commands; i++) {
        if (_strcmp(command, builtin_commands[i]) == 0) {
            return 1;
        }
    }

    return 0;
}
/*
 * shell_loop - Main loop for the simple shell
 *
 * This function reads user commands, processes them, and executes
 * either built-in commands or external programs.
 */
void shell_loop(void) {
    char **args = NULL;
    char *cmd = NULL;
    char *path = NULL;
    int exit_loop = 0;

    while (!exit_loop) {
        printf("$ "); /* Display a prompt */
        fflush(stdout);

        if (!isatty(STDIN_FILENO)) {
            exit_loop = 1; /* Exit the loop if not running in interactive mode */
        }

        cmd = _getcmd();
	if (cmd == NULL) {
            /* Ctrl+D was pressed, terminate the shell */
            printf("\n");
            exit_loop = 1;
            continue;
        }
        if (_strlen(cmd) == 0 || _strspn(cmd, " \t\n") == _strlen(cmd)) {
            printf("Not a valid command.\n");
            free(cmd);
            continue; /* Skip processing if the command is empty or contains only spaces */
        }

        args = get_token(cmd, " ");

        if (args[0] == NULL) {
            printf("No command entered.\n");
            free_args(args);
            free(cmd);
            continue; /* Skip processing if no command is entered */
        }
	if(is_builtin_command(args[0])){
                     execute_builtin_commands(args);
	}else
        {
            path = _getpath(args[0]);
            if(path == NULL)
		continue;
	    execute_external_command(path, cmd, args);
        }
        
        
    }
}
/*
 * free_args - Free memory allocated for an array of strings
 *
 * @args: The array of strings to free
 */
void free_args(char **args) {
    free(args);
}
