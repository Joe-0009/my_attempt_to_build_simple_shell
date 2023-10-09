#include "shell.h"
/**
 * add_alias_end - Adds a node to the end of an alias_t linked list.
 * @head: A pointer to the head of the alias_t linked list.
 * @alias_name: The name of the new alias to be added.
 * @alias_value: The value of the new alias to be added.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
alias_t *add_alias_end(alias_t **head, char *alias_name, char *alias_value)
{
	alias_t *new_alias_node = malloc(sizeof(alias_t));
	alias_t *last_node;

	if (!new_alias_node)
		return (NULL);

	new_alias_node->next = NULL;
	new_alias_node->name = malloc(sizeof(char) * (_strlen(alias_name) + 1));
	if (!new_alias_node->name)
	{
		free(new_alias_node);
		return (NULL);
	}
	new_alias_node->value = alias_value;
	_strcpy(new_alias_node->name, alias_name);

	if (*head)
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_alias_node;
	}
	else
		*head = new_alias_node;

	return (new_alias_node);
}

/**
 * free_alias_list - Frees an alias_t linked list.
 * @head: The head of the alias_t linked list.
 */
void free_alias_list(alias_t *head)
{
	alias_t *next_node;

	while (head)
	{
		next_node = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next_node;
	}
}
