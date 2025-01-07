#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
extern char **environ;
char *_getenv(const char *name);
char *find_command(const char *command);
int read_input(char *args[]);
void execute_command(char *args[]);
int main(void);
char *absolute_command(const char *command);

#endif
