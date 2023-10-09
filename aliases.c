#include "shell.h"

alias_t *aliases;

int shell_alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *current_alias = aliases;
	int i, ret = 0;
	char *alias_value;

	if (!args[0])
	{
		while (current_alias)
		{
			print_alias(current_alias);
			current_alias = current_alias->next;
		}
		return (ret);
	}

	for (i = 0; args[i]; i++)
	{
		current_alias = aliases;
		alias_value = _strchr(args[i], '=');
		if (!alias_value)
		{
			while (current_alias)
			{
				if (_strcmp(args[i], current_alias->name) == 0)
				{
					print_alias(current_alias);
					break;
				}
				current_alias = current_alias->next;
			}
			if (!current_alias)
			{
				ret = 1; /*Indicate an error occurred*/
				fprintf(stderr, "Alias '%s' not found\n", args[i]);
			}
		}
		else
		{
			set_alias(args[i], alias_value);
		}
	}
	return (ret);
}
void set_alias(char *alias_name, char *alias_value)
{
	alias_t *current_alias = aliases;
	int len, j, k;
	char *cleaned_value;

	*alias_value = '\0'; /*Remove the '=' at the beginning*/
	alias_value++;

	len = _strlen(alias_value) - _strspn(alias_value, "'\"");
	cleaned_value = malloc(sizeof(char) * (len + 1));

	if (!cleaned_value)
		return;

	for (j = 0, k = 0; alias_value[j]; j++)
	{
		if (alias_value[j] != '\'' && alias_value[j] != '"')
			cleaned_value[k++] = alias_value[j];
	}

	cleaned_value[k] = '\0';

	while (current_alias)
	{
		if (_strcmp(alias_name, current_alias->name) == 0)
		{
			free(current_alias->value);
			current_alias->value = cleaned_value;
			break;
		}
		current_alias = current_alias->next;
	}
	if (!current_alias)
		add_alias_end(&aliases, alias_name, cleaned_value);
}
void print_alias(alias_t *alias)
{
	char *alias_string;
	int alias_length = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (alias_length + 1));

	if (!alias_string)
		return;

	_strcpy(alias_string, alias->name);
	_strcat(alias_string, "='");
	_strcat(alias_string, alias->value);
	_strcat(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, alias_length);
	free(alias_string);
}
char **replace_aliases(char **command_args)
{
	alias_t *current_alias;
	int i;
	char *new_arg;

	if (_strcmp(command_args[0], "alias") == 0)
		return command_args;

	for (i = 0; command_args[i]; i++)
	{
		current_alias = aliases;

		while (current_alias)
		{
			if (_strcmp(command_args[i], current_alias->name) == 0)
			{
				new_arg = malloc(sizeof(char) * (_strlen(current_alias->value) + 1));

				if (!new_arg)
				{
					free_args_pair(command_args, command_args);
					return NULL;
				}

				_strcpy(new_arg, current_alias->value);
				free(command_args[i]);
				command_args[i] = new_arg;
				i--;
				break;
			}
			current_alias = current_alias->next;
		}
	}

	return command_args;
}
void free_args_pair(char **args1, char **args2)
{
	free_args(args1);
	free_args(args2);
}
