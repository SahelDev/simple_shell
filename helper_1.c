#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @first: First string to be compared
 * @second: Second string to be compared
 *
 * Return: Difference between the two strings
 */
int _strcmp(char *first, char *second) {
    int index = 0;

    while (first[index] != '\0') {
        if (first[index] != second[index])
            break;
        index++;
    }

    return (first[index] - second[index]);
}

/**
 * _strcat - Concatenates two strings
 * @destination: String to be concatenated to
 * @source: String to concatenate
 *
 * Return: Address of the new string
 */
char *_strcat(char *destination, char *source) {
    char *new_string = NULL;
    int len_dest = _strlen(destination);
    int len_source = _strlen(source);

    new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
    _strcpy(destination, new_string);
    _strcpy(source, new_string + len_dest);
    new_string[len_dest + len_source] = '\0';

    return (new_string);
}

/**
 * _strspn - Gets the length of a prefix substring
 * @str1: String to be searched
 * @str2: String to be used
 *
 * Return: Number of bytes in the initial segment of 'str1' which are part of 'str2'
 */
int _strspn(char *str1, char *str2) {
    int index = 0;
    int match = 0;

    while (str1[index] != '\0') {
        if (_strchr(str2, str1[index]) == NULL)
            break;
        match++;
        index++;
    }

    return (match);
}

/**
 * _strcspn - Computes segment of 'str1' which consists of characters not in 'str2'
 * @str1: String to be searched
 * @str2: String to be used
 *
 * Return: Index at which a character in 'str1' exists in 'str2'
 */
int _strcspn(char *str1, char *str2) {
    int len = 0;
    int i;

    for (i = 0; str1[i] != '\0'; i++) {
        if (_strchr(str2, str1[i]) != NULL)
            break;
        len++;
    }

    return (len);
}

/**
 * _strchr - Locates a character in a string
 * @s: String to be searched
 * @c: Character to be checked
 *
 * Return: Pointer to the first occurrence of 'c' in 's'
 */
char *_strchr(char *s, char c) {
    int i = 0;

    for (; s[i] != c && s[i] != '\0'; i++)
        ;
    if (s[i] == c)
        return (s + i);
    else
        return (NULL);
}
