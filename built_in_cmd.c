#include "shell.h"

/**
 * check_bltin_cmd - checks if the command entered is a built-in
 * @line: input entered by user
 * @ar: array that can be handled by execve
 * @newline: duplicate of line
 * @array: Tokens to check
 * Return: Return depends upon if the built-in was found
 */
int check_bltin_cmd(char *line, char **ar, char *newline, char **array)
{
	int i = 0;

	if (_strcmp(ar[0], "exit") == 0) /* compares first token to exit */
	{
		_free(line, ar, newline, array);
		_exit(errno); /* exits with status 0 or errno */
	}
	if (_strcmp(ar[0], "env") == 0) /* compares first token to env */
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			_puts(environ[i]); /* prints string of environ */
			write(1, "\n", 1);
		}
		return (2);
	}
	return (0);
}
