#include "main.h"

/**
 * _strcmp - Compares pointers to two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 * Return: If str1 < str2, the negative difference of
 * the first unmatched characters.
 *         If s1 == s2, 0.
 *         If s1 > s2, the positive difference of
 *         the first unmatched characters.
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strcpy - copie a string from source to destination
 * @source: the string source
 * @dest: the string destination
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _isalpha - check if the input is a letter
 * @c: the character to be checked
 * Return: 1 if letter, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (SUCCESS);
	}
	return (FAIL);
}

/**
 * _strcat - concatenates two string in a path form
 * @first: the first given destination
 * @second: the second given source
 * Return: (Success) to the newly string
 * ------- (Fail) if it failed
 */

char *_strcat(char *first, char *second)
{
	int len1, len2, i = 0, j = 0;
	char *result;

	len1 = _strlen(first);
	len2 = _strlen(second);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	while (first[j])
		result[i++] = first[j++];
	result[i++] = '/';
	j = 0;
	while (second[j])
		result[i++] = second[j++];
	result[i] = '\0';
	return (result);
}

/**
 * _strlen - finds the length of a given string
 * @str: the given string
 * Return: (Success) the length of the string
 * ------- (Fail) negative value
 */

int _strlen(char *str)
{
	char *ptr;

	if (str == NULL)
		return (-1);
	for (ptr = str; *ptr; ptr++)
				;
	return (ptr - str);
}
