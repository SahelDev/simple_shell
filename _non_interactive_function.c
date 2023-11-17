#include "shell.h"

/**
 * handle_non_interactive - handles non_interactive mode
 *
 * Return: void
 */

void handle_non_interactive(void)
{
    char **current_command = NULL;
    int i, type_command = 0;
    size_t n = 0;

    if (!(isatty(STDIN_FILENO)))
    {
        while (getline(&line, &n, stdin) != -1)
        {
            remove_newline(line);
            remove_comment(line);
            commands = tokenize_input(line, ";");
            for (i = 0; commands[i] != NULL; i++)
            {
                current_command = tokenize_input(commands[i], " ");
                if (current_command[0] == NULL)
                {
                    free(current_command);
                    break;
                }
                type_command = parse_cmd(current_command[0]);
                start_execution(current_command, type_command);
                free(current_command);
            }
            free(commands);
        }
        free(line);
        exit(status);
    }
}
