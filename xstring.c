#include "main.h"

/**
 * _strchr - locates a character in a given string
 * @str: the given string
 * @c: the given string
 * Return: (Success) a pointer to the first occurence of c
 * ------- (Fail) return a null pointer
 */

char *_strchr(char *str, char c)
{
	char *ptr;

	for (ptr = str; *ptr; ptr++)
		if (*ptr == c)
			return (ptr);
	return (NULL);
}

/**
 * _strdup - dupicates string
 * @str: the given string
 * Return: (Success) a pointer to the duplicated string
 * ------- (Fail) return a null pointer
 */

char *_strdup(char *str)
{
	char *dupl;

	if (str == NULL)
		return (NULL);
	dupl = malloc(_strlen(str) + 1);
	if (dupl == NULL)
		return (NULL);
	_strcpy(dupl, str);
	return (dupl);
}
