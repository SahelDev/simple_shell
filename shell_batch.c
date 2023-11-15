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
	int num_tokens;

	while (getline(&line, &bufsize, stdin) > 0)
	{
		num_tokens = num_count(line);
		parse(line, num_tokens, argv);
		line = NULL;
	
	}
	free(line);
	return (0);
}
