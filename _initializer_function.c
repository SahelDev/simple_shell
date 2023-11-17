#include "_shell.h"

/**
 * start_execution - starts executing everything
 * @current_command: try to check current token
 * @type_command: parse token
 *
 * Return: void function
 */

void start_execution(char **current_command, int type_command)
{
    pid_t PID;

    if (type_command == EXT_CMD || type_command == PATH_CMD)
    {
        PID = fork();
        if (PID == 0)
            execute_cmd(current_command, type_command);
        else
        {
            waitpid(PID, &status, 0);
            status >>= 8;
        }
    }
    else
        execute_cmd(current_command, type_command);
}
