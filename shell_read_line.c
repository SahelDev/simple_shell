#include "shell.h"

/**
 * read_line - reading line from stdin
 * Return: User input
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			perror("Detect Ctrl+D or EOF");
			exit(EXIT_SUCCESS);
		}
		else
		{	free(line);
			perror("Error while reading line");
			exit(EXIT_FAILURE);
	}
	}
	return (line);
}
