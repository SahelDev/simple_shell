#include "_shell.h"

/**
 * determine_command_type - determines the type of the command
 * @command: command to be parsed
 *
 * Return: constant representing the type of the command
 * Description -
 *       PATH_CMD (1) represents commands like /bin/ls
 *       INT_CMD (2) represents commands like exit, env
 *       PATH_CMD (3) represents commands found in the PATH like ls
 *       INVALID_CMD (-1) represents invalid commands
 */

int determine_command_type(char *command)
{
    int i;
    char *internal_commands[] = {"env", "exit", NULL};
    char *path = NULL;

    for (i = 0; command[i] != '\0'; i++)
    {
        if (command[i] == '/')
            return (EXT_CMD);
    }
    for (i = 0; internal_commands[i] != NULL; i++)
    {
        if (compare_strings(command, internal_commands[i]) == 0)
            return (INT_CMD);
    }
    path = find_cmd_path(command);
    if (path != NULL)
    {
        free(path);
        return (PATH_CMD);
    }

    return (INVALID_CMD);
}

/**
 * run_command - executes a command based on its type
 * @tokenized_command: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @command_type: type of the command
 *
 * Return: void
 */
void run_command(char **tokenized_command, int command_type)
{
    void (*function)(char **command);

    if (command_type == EXT_CMD || command_type == PATH_CMD)
    {
        if (execute_external_command(tokenized_command, command_type) == -1)
        {
            display_error(_getenv("PWD"));
            exit(2);
        }
    }
    if (command_type == INT_CMD)
    {
        function = fetch_function(tokenized_command[0]);
        function(tokenized_command);
    }
    if (command_type == INVALID_CMD)
    {
        display_error(shell_name, STDERR_FILENO);
        display_error(": 1: ", STDERR_FILENO);
        display_error(tokenized_command[0], STDERR_FILENO);
        display_error(": not found\n", STDERR_FILENO);
        status = 127;
    }
}

/**
 * find_cmd_path - checks if a command is found in the PATH
 * @command: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 */
char *find_cmd_path(char *command)
{
    char **path_array = NULL;
    char *temp, *temp2, *path_cpy;
    char *path = _getenv("PATH");
    int i;

    if (path == NULL || string_length(path) == 0)
        return (NULL);
    path_cpy = malloc(sizeof(*path_cpy) * (string_length(path) + 1));
    copy_string(path, path_cpy);
    path_array = tokenize_input(path_cpy, ":");
    for (i = 0; path_array[i] != NULL; i++)
    {
        temp2 = concatenate_strings(path_array[i], "/");
        temp = concatenate_strings(temp2, command);
        if (check_access(temp, F_OK) == 0)
        {
            free(temp2);
            free(path_array);
            free(path_cpy);
            return (temp);
        }
        free(temp);
        free(temp2);
    }
    free(path_cpy);
    free(path_array);
    return (NULL);
}

/**
 * fetch_function - retrieves a function based on the command given and a mapping
 * @command: string to check against the mapping
 *
 * Return: pointer to the proper function, or null on fail
 */
void (*fetch_function(char *command))(char **)
{
    int i;
    function_mapping mapping[] = {
        {"env", display_env}, {"exit", quit_shell}
    };

    for (i = 0; i < 2; i++)
    {
        if (compare_strings(command, mapping[i].command_name) == 0)
            return (mapping[i].func);
    }
    return (NULL);
}

/**
 * retrieve_env_var - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *retrieve_env_var(char *name)
{
    char **my_environ;
    char *pair_ptr;
    char *name_cpy;

    for (my_environ = environ; *my_environ != NULL; my_environ++)
    {
        for (pair_ptr = *my_environ, name_cpy = name;
             *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
        {
            if (*pair_ptr == '=')
                break;
        }
        if ((*pair_ptr == '=') && (*name_cpy == '\0'))
            return (pair_ptr + 1);
    }
    return (NULL);
}
