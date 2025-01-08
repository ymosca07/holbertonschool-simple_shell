#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes des fonctions */
/* Fonctions principales */
int read_input(char *args[]);
void execute_command(char *args[], char *argv[]);

/* Fonctions de recherche de commandes */
char *find_command(const char *command);
char *absolute_command(const char *command);
void build_path(char *dir, const char *command, char *full_path);

/* Fonctions intégrés au shell */
int gestion_builtin(char **args);
void print_env(void);

/* Fonctions utilitaires */
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);

/* Variable d'environnement */
extern char **environ;

#endif
