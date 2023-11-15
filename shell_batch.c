#include "shell.h"








int shell_batch(char *argv[])
{
while (getline(&line, &bufsize, stdin) > 0)
{
	num_tokens = num_count(line);
	parse(line, num_tokens, argv, cmdcount);
	line = NULL;
	
}
	free(line);
	return (0);
}
