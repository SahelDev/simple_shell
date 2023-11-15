#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**
 * struct fmt - types of data and their function
 * @ltr: the type of data
 * @type: pointer to function for type
 */
typedef struct fmt
{
	char *ltr;
	int (*type)();
} fmt;
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

int exe_(char *line, char **ar, char *nln, char **arry, char **argv, int er);
void _free(char *line, char **ar, char *newline, char **array);
int _strncmp(char *s1, char *s2, int len);
int check_bltin_cmd(char *line, char **ar, char *newline, char **array);
int num_count(char *line);
int search_path(char *p, char **tokens);
int find_on_path(char **tokens);
void execute_path(char *p, char **tokens);
int _printf(const char *format, ...);
int chk_fmt(va_list *args, const char *format, int i);
int pr_chr(va_list *args);
int pr_str(va_list *args);
int pr_dgt(va_list *args);
void _puts(char *str);
void get_digits(int n);
int _putchar(char c);
void change_dir(char **ar);
int shell_batch(char *argv[]);
int shell_no_batch(char *argv[], int shell_interaction);
char *read_line(void);

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Holds pseudo-arguments to be passed into a function,
 *                   enabling a consistent prototype for the function pointer structure.
 * @arg: A string obtained from getline containing arguments.
 * @argv: An array of strings generated from arg.
 * @path: String path for the current command.
 * @argc: Argument count.
 * @line_count: Error line count.
 * @err_num: Error code for exit().
 * @linecount_flag: If set, count this line of input.
 * @fname: Program filename.
 * @env: Local copy of the linked list of environ.
 * @environ: Custom modified copy of environ from the linked list env.
 * @history: History node.
 * @alias: Alias node.
 * @env_changed: Set if environ was modified.
 * @status: Return status of the last exec'd command.
 * @cmd_buf: Address of the pointer to cmd_buf, set if chaining.
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: File descriptor from which to read line input.
 * @histcount: History line number count.
 */

typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    list_t *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;

    char **cmd_buf; /* Address of the pointer to cmd_buf, set if chaining, for memory management */
    int cmd_buf_type; /* CMD_type ||, &&, ; */
    int readfd;
    int histcount;
} info_t;

/**
 * struct ParseResult - contains the result of the parse operation
 * @command: the command string
 * @arguments: array of arguments
 * @num_arguments: number of arguments in the array
 */
typedef struct ParseResult
{
    char *command;
    char **arguments;
    int num_arguments;
} ParseResult;




























#endif
