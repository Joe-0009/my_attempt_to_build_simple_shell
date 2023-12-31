#ifndef SHELL_H
#define SHELL_H

#define MAX_TOKENS 100
extern char **environ;

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
typedef struct alias_s {
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Function Declarations */
void free_args(char **args);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char * _getcmd(void);
char *_getpath(const char *command);
int is_builtin_command(const char *command);
char **get_token(char *cmd, char *delim);
void shell_loop(void);
int executor(const char* path, char **args);
int execute_external_command(char *path, char *cmd, char **args);
int execute_builtin_commands(char **args);
void free_alias_list(alias_t *head);
alias_t *add_alias_end(alias_t **head, char *alias_name, char *alias_value);
char **replace_aliases(char **command_args);
void print_alias(alias_t *alias);
void set_alias(char *alias_name, char *alias_value);
void free_args_pair(char **args1, char **args2);

/* built_in functions */
void __exiT(char **args);
int _env(void);
void _exiT(char **args);
char *_strtok(char *str, const char *delim);
int _cd(const char *target_dir);
int shell_alias(char **args, char __attribute__((__unused__)) **front);

/* alloc functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* string handlers */
char *_strncpy(char *dest, char *src, int n);
int _strcmp(const char *s1, const char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char c);
int _atoi(char *s);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
char *_memcpy(char *dest,char *src, unsigned int n);
int _strspn(char *s, char *accept);
char *_strcat(char *destination, const char *source);

/*env builtins */
int _env(void);
int _setenv(const char *name, const char *value);
int environ_size(void);
int _unsetenv(const char *name);
char *_getenv(const char *name);

#endif /*SHEEL_H*/

