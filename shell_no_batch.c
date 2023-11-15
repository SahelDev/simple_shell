#include"shell.h"

/**
 * shell_no_batch -function that handle shell in interactive mode
 * @argv:array of arg
 * @shell_interaction: determine shell mode
 * Return: void
 */

int shell_no_batch(char *argv[], int shell_interaction)
{

	int num_tokens = 0, cmdcount = 1;
	char *line;

	while (shell_interaction)/* if interactive */
	{
		write(1, "($) ", 4);
		num_tokens = 0;
		line = read_line();
		num_tokens = num_count(line); /* counts tokens */
		_parse(line, num_tokens, argv, cmdcount);
		cmdcount++;
		/* sends line and numtoken to parser - tracks fails*/
		line = NULL; /* resets line to null */
	}
	return (0);
}

