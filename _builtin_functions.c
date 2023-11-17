#include "_shell.h"

/**
 * environment - prints the current_environnement
 * @tokenized_command: command entered
 *
 * Return: void
 */

void environment(char **tokenized_command __attribute__((unused)))
{
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        display(environ[i], STDOUT_FILENO);
        display("\n", STDOUT_FILENO);
    }
}

/**
 * exit_program - exits the shell
 * @tokenized_command: command entered
 *
 * Return: void
 */

void exit_program(char **tokenized_command)
{
    int num_token = 0, arg;

    for (; tokenized_command[num_token] != NULL; num_token++)
        ;
    if (num_token == 1)
    {
        release_memory(tokenized_command);
        release_memory(line);
        release_memory(commands);
        exit(program_status);
    }
    else if (num_token == 2)
    {
        arg = convert_to_integer(tokenized_command[1]);
        if (arg == -1)
        {
            display(system_name, STDERR_FILENO);
            display(": 1: exit: Illegal number: ", STDERR_FILENO);
            display(tokenized_command[1], STDERR_FILENO);
            display("\n", STDERR_FILENO);
            program_status = 2;
        }
        else
        {
            release_memory(line);
            release_memory(tokenized_command);
            release_memory(commands);
            exit(arg);
        }
    }
    else
        display("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
