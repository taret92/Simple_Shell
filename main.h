#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

/**
 * struct built_in - Struct from shell
 * @name: Type character
 * @function: Type integer
 */
typedef struct built_in
{
	char *name;
	int (*function)(char **);
} command_t;

#define SIGN_S "($)"
void execute(char **tokens);
char *PATH(char *comm);
pid_t fork(void);
char **_strtok(char **tokens, char *str, char *delim);
int exe_exit(char **tokens);
char *line_read(void);
void ctrl_c(int sig);
int _putchar(char c);
int _strlen(char *s);
char *_strcat(char *dest, char *src);

#endif
