#include "shell.h"

/**
 * print_environment - prints the current environment variables
 * @tokenized_command: command entered
 *
 * This function prints the current environment variables.
 * Returns: void
 */
void print_environment(char **tokenized_command __attribute__((unused)))
{
    int env_index;

    for (env_index = 0; environ[env_index] != NULL; env_index++)
    {
        print(environ[env_index], STDOUT_FILENO);
        print("\n", STDOUT_FILENO);
    }
}

/**
 * shell_exit - exits the shell
 * @tokenized_command: command entered
 *
 * This function handles the shell exit command.
 * Returns: void
 */
void shell_exit(char **tokenized_command)
{
    int num_tokens = 0, exit_status;

    for (; tokenized_command[num_tokens] != NULL; num_tokens++)
        ;

    if (num_tokens == 1)
    {
        free(tokenized_command);
        free(line);
        free(commands);
        exit(status);
    }
    else if (num_tokens == 2)
    {
        exit_status = _atoi(tokenized_command[1]);

        if (exit_status == -1)
        {
            print(shell_name, STDERR_FILENO);
            print(": 1: exit: Illegal number: ", STDERR_FILENO);
            print(tokenized_command[1], STDERR_FILENO);
            print("\n", STDERR_FILENO);
            status = 2;
        }
        else
        {
            free(line);
            free(tokenized_command);
            free(commands);
            exit(exit_status);
        }
    }
    else
    {
        print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
    }
}
