#include "shell.h"
/**
 * _getpath - it gets the full path related to the command
 *
 * @command: the command
 *
 * return: full path
 */
 
char *_getpath(const char *command)
{
	char *path = getenv("PATH");
	char *token = NULL;
	char *full_path = NULL;
	char *path_copy;
	size_t full_path_size;

	if (path == NULL || command == NULL)
	{
        return (NULL);
	}
	if (access(command, X_OK) == 0)
	{
		return strdup(command);
	}
	/* Create a copy of the PATH to avoid modifying the original*/
	path_copy = _strdup(path);

	 if (path_copy == NULL)
	 {
		 perror("strdup");
		 return (NULL);
	 }

	 token = _strtok(path_copy, ":");
	 while (token != NULL)
	 {
		 full_path_size = strlen(token) + 1 + _strlen(command) + 1;
		 full_path = (char *)malloc(full_path_size);

		 if (full_path == NULL)
		 {
			 perror("malloc");
			 free(path_copy);
			 return (NULL);
		 }

		 snprintf(full_path, full_path_size, "%s/%s", token, command);

		 if (access(full_path, X_OK) == 0)
		 {
			 free(path_copy);
			 return (full_path);
		 }

		 free(full_path);
		 token = _strtok(NULL, ":");
	 }

	 free(path_copy);
	 return (NULL);
}
char *_getpath(const char *command) {
    char *path = _getenv("PATH");
    char *token = NULL;
    char *full_path = NULL;
    char *path_copy;
    size_t full_path_size;

    if (path == NULL || command == NULL) {
        return NULL;
    }
    if (access(command, X_OK) == 0) {
            return strdup(command);
        }
    /* Create a copy of the PATH to avoid modifying the original*/
    path_copy = _strdup(path);

    if (path_copy == NULL) {
        perror("strdup");
        return NULL;
    }

    token = _strtok(path_copy, ":");
    while (token != NULL) {
        full_path_size = strlen(token) + 1 + _strlen(command) + 1;
        full_path = (char *)malloc(full_path_size);

        if (full_path == NULL) {
            perror("malloc");
            free(path_copy);
            return NULL;
        }

        snprintf(full_path, full_path_size, "%s/%s", token, command);

        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        token = _strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

