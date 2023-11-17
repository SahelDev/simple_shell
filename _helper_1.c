#include "shell.h"

/**
 * compare_strings - compare two strings
 * @first: first string to be compared
 * @second: second string to be compared
 *
 * Return: difference of the two strings
 */

int compare_strings(char *first, char *second)
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
 * concatenate_strings - concatenates two strings
 * @destination: string to be concatenated to
 * @source:  string to concatenate
 *
 * Return: address of the new string
 */

char *concatenate_strings(char *destination, char *source)
{
    char *new_string =  NULL;
    int len_dest = string_length(destination);
    int len_source = string_length(source);

    new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
    copy_string(destination, new_string);
    copy_string(source, new_string + len_dest);
    new_string[len_dest + len_source] = '\0';
    return (new_string);
}

/**
 * string_span - gets the length of a prefix substring
 * @str1: string to be searched
 * @str2: string to be used
 *
 * Return: number of bytes in the initial segment of 5 which are part of accept
 */

int string_span(char *str1, char *str2)
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
 * string_c_span - computes segment of str1 which consists of characters not in str2
 * @str1: string to be searched
 * @str2: string to be used
 *
 * Return: index at which a char in str1 exists in str2
 */


int string_c_span(char *str1, char *str2)
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
 * find_character - locates a char in a string
 * @s: string to be searched
 * @c: char to be checked
 *
 * Return: pointer to the first occurrence of c in s
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
