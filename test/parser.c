#include "shell.h"

/**
 * is_executable - Determines if a file is an executable command.
 * @info: The information structure.
 * @path: Path to the file.
 *
 * Returns: 1 if true, 0 otherwise.
 */
int is_executable(info_t *info, char *path)
{
    struct stat st;

    (void)info;
    if (!path || stat(path, &st))
        return (0);

    if (st.st_mode & S_IFREG)
    {
        return (1);
    }
    return (0);
}

/**
 * duplicate_chars - Duplicates characters.
 * @pathstr: The PATH string.
 * @start: Starting index.
 * @stop: Stopping index.
 *
 * Returns: Pointer to the new buffer.
 */
char *duplicate_chars(char *pathstr, int start, int stop)
{
    static char buf[1024];
    int i = 0, k = 0;

    for (k = 0, i = start; i < stop; i++)
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];
    buf[k] = 0;
    return (buf);
}

/**
 * find_in_path - Finds the command in the PATH string.
 * @info: The information structure.
 * @pathstr: The PATH string.
 * @cmd: The command to find.
 *
 * Returns: Full path of the command if found, otherwise NULL.
 */
char *find_in_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path;

    if (!pathstr)
        return (NULL);
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_executable(info, cmd))
            return (cmd);
    }
    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            path = duplicate_chars(pathstr, curr_pos, i);
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }
            if (is_executable(info, path))
                return (path);
            if (!pathstr[i])
                break;
            curr_pos = i;
        }
        i++;
    }
    return (NULL);
}

/**
 * parse - Parses a line into command and arguments.
 * @line: The input line.
 * @num_tokens: Number of tokens in the line.
 *
 * Return: A ParseResult struct containing the parsed data.
 */
ParseResult parse(char *line, int num_tokens)
{
    ParseResult result;
    result.command = NULL;
    result.arguments = NULL;
    result.num_arguments = 0;

    if (num_tokens <= 0) {
        return result;
    }

    result.command = strdup(line);

    result.arguments = split_string(line, " ");
    if (result.arguments != NULL) {
        result.num_arguments = 0;
        while (result.arguments[result.num_arguments] != NULL) {
            result.num_arguments++;
        }
    }

    return result;
}

/**
 * free_parse_result - Libère la mémoire allouée pour une structure ParseResult.
 * @result: La structure ParseResult à libérer.
 */
void free_parse_result(ParseResult *result)
{
    if (result == NULL) {
        return;
    }

    free(result->command);
    free_string_array(result->arguments);

    result->command = NULL;
    result->arguments = NULL;
    result->num_arguments = 0;
}
