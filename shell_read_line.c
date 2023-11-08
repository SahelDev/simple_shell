#include "shell.h"

/**
 * read_line - reading line from stdin
 * Return: User input 
 */

char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin)){
			free(line);
		       	perror("Detect Ctrl+D or EOF");	
			exit(EXIT_SUCCESS); // we get an EOF
		}
		else
		{	free(line);
			perror("Error while reading line");
			exit(EXIT_FAILURE);


	}
	}
	// Need to free memory after consuming the return value in MAiN function.
	
	return (line) ;
}

/*int main(void)
{
	char *c ;

	c = read_line();
	

	printf("%s\n ", c);
	free(c);

	return (0);




}*/



