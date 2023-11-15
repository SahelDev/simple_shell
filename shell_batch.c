#include "shell.h"


/**
 * shell_batch-handle shell in non interactive mode
 * @argv : array of args
 * Return: int
 */
int shell_batch(char *argv[])
{
	char *line;
	size_t bufsize;
	int num_tokens, cmdcount = 1;

	while (getline(&line, &bufsize, stdin) > 0)
	{
		num_tokens = num_count(line);
		_parse(line, num_tokens, argv, cmdcount);
		line = NULL;

	}
	free(line);
	return (0);
}
