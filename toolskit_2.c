#include "shell.h"

/**
 * _puts - functiont to write strinng to standard out
 * @str: string to write
 */
void _puts(char *str)
{
	while (*str  != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

/**
 * pr_str - prints strings from arg
 * @args: argument pointer
 *
 * Return: count of string elements printed
 */
int pr_str(va_list *args)
{
	int x = 0;
	char *ar;

	ar = va_arg(*args, char *);
	while (*ar != '\0')
	{
		_putchar(*ar);
		x++;
		ar++;
	}
	return (x);
}
/**
 * _putchar - writes the character c to sterr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}
/**
 * _strcpy - copies str from src to dest
 * @src: source string
 * @dest: destination string
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int len = 0;

	while (*(src + len) != '\0')
	{
		len++;
	}

	for (i = 0; i <= len; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
