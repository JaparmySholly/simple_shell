#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

/* Global variable */
extern char **environ;

/* Macros */
#define BUFSIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PROMPT "#:)-$ "
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/* Struct */

/**
 * struct sh_data - Global data structure
 * @line: the line input
 * @args: the arguments token
 * @error_msg: the global path
 * @cmd: the parsed command
 * @index: the command index
 * @oldpwd: the old path visited
 * @env: the environnment
 * Description: A structure contains all the variables needed to manage
 * the program, memory and accessability
 */

typedef struct sh_data
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} sh_t;

/**
 * struct builtin - Manage the builtin functions
 * @cmd: the command line on string form
 * @f: the associated function
 * Description: this struct made to manage builtins cmd
 */

typedef struct builtin
{
	char *cmd;
	int (*f)(sh_t *data);
} blt_t;

int execute(sh_t *);
int read_line(sh_t *);
int split_line(sh_t *);
int parse_line(sh_t *);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *source);
char *_strdup(char *str);
char *_strcat(char *first, char *second);
int _strlen(char *str);
char *_strchr(char *str, char c);

/* ----------Memory prototype------------*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_memset(void *s, int c, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
int free_data(sh_t *);

/* ----------Tools prototype-------------*/
void *fill_an_array(void *a, int el, unsigned int len);
void signal_handler(int signo);
char *_getenv(char *path_name, sh_t *data);
void index_cmd(sh_t *data);
void array_rev(char *arr, int len);

/* ----------xtools prototype--------*/
char *itoa(unsigned int n);
int intlen(int num);
int _atoi(char *c);
int print_error(sh_t *data);
int write_history(sh_t *data);
int _isalpha(int c);

/* -------------Builtins-----------------*/
int abort_prg(sh_t *data);
int change_dir(sh_t *data);
int display_help(sh_t *data);
int handle_builtin(sh_t *data);
int check_builtin(sh_t *data);

/* -------------Parse-----------------*/
int is_path_form(sh_t *data);
void is_short_form(sh_t *data);
int is_builtin(sh_t *data);

#endif
