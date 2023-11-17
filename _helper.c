#include "_shell.h"

/**
 * tokenize_input - tokenizes input and stores it into an array
 * @input_string: input to be parsed
 * @delim: delimiter to be used, needs to be one character string
 *
 * Return: array of tokens
 */

char **tokenize_input(char *input_string, char *delim)
{
    int num_delim = 0;
    char **av = NULL;
    char *token = NULL;
    char *save_ptr = NULL;

    token = tokenize_string_r(input_string, delim, &save_ptr);

    while (token != NULL)
    {
        av = resize_memory(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
        av[num_delim] = token;
        token = tokenize_string_r(NULL, delim, &save_ptr);
        num_delim++;
    }

    av = resize_memory(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
    av[num_delim] = NULL;

    return (av);
}

/**
 * display - prints a string to stdout
 * @string: string to be printed
 * @stream: stream to print out to
 *
 * Return: void, return nothing
 */
void display(char *string, int stream)
{
    int i = 0;

    for (; string[i] != '\0'; i++)
        write(stream, &string[i], 1);
}

/**
 * remove_newline - removes new line from a string
 * @str: string to be used
 *
 * Return: void
 */

void remove_newline(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            break;
        i++;
    }
    str[i] = '\0';
}

/**
 * copy_string - copies a string to another buffer
 * @source: source to copy from
 * @dest: destination to copy to
 *
 * Return: void
 */

void copy_string(char *source, char *dest)
{
    int i = 0;

    for (; source[i] != '\0'; i++)
        dest[i] = source[i];
    dest[i] = '\0';
}

/**
 * string_length - counts string length
 * @string: string to be counted
 *
 * Return: length of the string
 */

int string_length(char *string)
{
    int len = 0;

    if (string == NULL)
        return (len);
    for (; string[len] != '\0'; len++)
        ;
    return (len);
}
