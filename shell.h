#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

extern char **environ;
char *_getenv(const char *name);
char *find_command(const char *command);
int read_input(char *args[]);
void execute_command(char *args[]);
int main(void);
char *absolute_command(const char *command);

#endif
