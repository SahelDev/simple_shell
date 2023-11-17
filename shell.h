#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


/*constants*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct map - a struct that maps a command name to a function 
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

extern char **print_current_environmentiron;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/*helpers*/
void print(char *, int);
char **tokenizer(char *, char *);
void remove_newline(char *);
int _strlen(char *);
void _strcpy(char *, char *);

/*helpers2*/
int string_compare(char *, char *);
char *string_concat(char *, char *);
int _strspn(char *, char *);
int prefix_substring_length(char *, char *);
char *find_character(char *, char);

/*helpers3*/
char *tokenize_string(char *, char *, char **);
int string_to_integer(char *);
void *reallocate_memory(void *ptr, unsigned int old_size, unsigned int new_size);
void handle_ctrl_c(int);
void ignore_comment(char *);

/*utils*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getprint_current_environment(char *);

/*built_in*/
void print_current_environment(char **);
void exit_shell(char **);

/*main*/
extern void handle_non_interactive_mode(void);
extern void initializer(char **current_command, int type_command);

#endif /*SHELL_H*/


