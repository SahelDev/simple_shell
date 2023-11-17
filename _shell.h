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

/* Constants */
#define EXT_CMD 1
#define INT_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct mapping - a struct that maps a command name to a function 
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct mapping
{
    char *command_name;
    void (*func)(char **command);
} function_mapping;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/* Helpers */
void display(char *, int);
char **tokenize_input(char *, char *);
void remove_newline(char *);
int string_length(char *);
void copy_string(char *, char *);

/* Helpers 2 */
int compare_strings(char *, char *);
char *concatenate_strings(char *, char *);
int string_span(char *, char *);
int string_c_span(char *, char *);
char *find_character(char *, char);

/* Helpers 3 */
char *tokenize_string_r(char *, char *, char **);
int convert_to_integer(char *);
void *resize_memory(void *ptr, unsigned int old_size, unsigned int new_size);
void interrupt_handler(int);
void ignore_comments(char *);

/* Utils */
int determine_command_type(char *);
void run_command(char **, int);
char *find_cmd_path(char *);
void (*fetch_function(char *))(char **);
char *retrieve_env_var(char *);

/* Built-in */
void display_env(char **);
void quit_shell(char **);

/* Main */
extern void handle_non_interactive(void);
extern void start_execution(char **current_command, int type_command);

#endif /* SHELL_H */
