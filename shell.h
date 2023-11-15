#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
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
int parse_args(char *line, int num_tokens, char *argv[], int failcount);
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
void shell_batch(void);
void shell_no_batch(void);































#endif
