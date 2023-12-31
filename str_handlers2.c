#include "shell.h"


/**
 * _strlen - returns the length of a string
 *
 * @s: the input of string
 *
 * Return: the length
 */

int _strlen(const char *s)

{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
/**
 * *_strcpy - copies a string to another one
 *
 * @src: input first string
 * @dest: input second string
 *
 * Return: pointer to the copied string
 */




char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (ptr);
}
/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}
/**
 * *_memcpy - copies memory area
 * @dest: destination memory area
 * @src: memory area to copy from
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
/**
 *_strcat - Concatenates two strings.
 * @destination: Pointer to the destination string.
 * @source: Pointer to the source string.
 *
 * Return: Pointer to the destination string.
 */
char *_strcat(char *destination, const char *source)
{
	char *dest_ptr = destination;
	const char *src_ptr = source;

	/*Move dest_ptr to the end of the destination string*/
	while (*dest_ptr != '\0')
		dest_ptr++;

	/*Copy characters from source to destination*/
	while (*src_ptr != '\0')
		*dest_ptr++ = *src_ptr++;
	/*Null-terminate the destination string*/
	*dest_ptr = '\0';

	return destination;
}

