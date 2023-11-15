#include"shell.h"
/**
 * shell_no_batch -function that handle shell in interactive mode 
 * @P1:
 * Return: void
 */

int shell_no_batch(char *argv[], int shell_interaction)
{	
	size_t bufsize = 0;
	int i, num_tokens = 0, cmdcount = 1;

	while (shell_interaction)/* if interactive */
	{
		write(1, "($) ", 4);
		num_tokens = 0; 
		i = getline(&line, &bufsize, stdin); 
		if (i < 0)
		{
			free(line);
			write(1, "\n", 1);
			/* frees, skips line, and repeats for failed input or CTRL - D */
			break;
		}
		num_tokens = num_count(line); /* counts tokens */
		parse(line, num_tokens, argv, cmdcount);
		cmdcount++;
		/* sends line and numtoken to parser - tracks fails*/
		line = NULL; /* resets line to null */
	}
	return (0);
}

