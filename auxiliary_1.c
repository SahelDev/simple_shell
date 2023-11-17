#include "shell.h"

/**
 * string_compare - Compares two strings
 * @str1: First string to be compared
 * @str2: Second string to be compared
 *
 * Return: Difference between the two strings
 */

int string_compare(char *first, char *second)
{
	int i = 0;

	while (first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}
	return (first[i] - second[i]);
}

/**
 * string_concat - Concatenates two strings
 * @dest: String to concatenate to
 * @src: String to be concatenated
 *
 * Return: Pointer to the resulting concatenated string
 */

char *string_concat(char *destination, char *source)
{
	char *new_string =  NULL;
	int len_dest = _strlen(destination);
	int len_source = _strlen(source);

	new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
	_strcpy(destination, new_string);
	_strcpy(source, new_string + len_dest);
	new_string[len_dest + len_source] = '\0';
	return (new_string);
}

/**
 *_strspn - gets the length of a prefix substring
 *@str1: string to be searched
 *@str2: string to be used
 *
 *Return: number of bytes in the initial segment of 5 which are part of accept
 */

int _strspn(char *str1, char *str2)
{
	int i = 0;
	int match = 0;

	while (str1[i] != '\0')
	{
		if (find_character(str2, str1[i]) == NULL)
			break;
		match++;
		i++;
	}
	return (match);
}

/**
 * prefix_substring_length - Gets the length of a prefix substring
 * @str: String to be searched
 * @prefix: Substring to search for as a prefix
 *
 * Return: Number of bytes in the initial segment of 'str' which form 'prefix'
 */


int prefix_substring_length(char *str1, char *str2)
{
	int len = 0, i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (find_character(str2, str1[i]) != NULL)
			break;
		len++;
	}
	return (len);
}

/**
 * find_character - Locates a character in a string
 * @str: String to be searched
 * @ch: Character to be located
 *
 * Return: Pointer to the first occurrence of 'ch' in 'str'
 */

char *find_character(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

