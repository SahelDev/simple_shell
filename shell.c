#include "shell.h"

/**
 * main - entry point of our shell
 * @argc: arg count
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	/* determines if file descriptor is associated with a terminal */
	if (isatty(STDIN_FILENO) == 0 && argc == 1)
	{
		shell_batch();
	}
	else
	{
		shell_no_batch();
	}
	return (0);
}
