#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * read_input - lit l'entrée de l'utilisateur
 * et sépare la commande des arguments
 * @args: tableau pour stocker les arguments séparés
 * Return: 0 si réussite, 1 si échec
 */
int read_input(char *args[])
{
	char *token, *input = NULL; /* stock l'entrée utilisateur */
	size_t input_size = 0; /* taille de l'entrée */
	ssize_t read_size; /* taille lue */
	int i;

	printf("$ ");
	read_size = getline(&input, &input_size, stdin);

	if (read_size == -1) /* vérifier EOF ou erreur */
	{
		printf("\n");
		free(input);
		exit(1);
	}

	if (input[read_size - 1] == '\n')
		input[read_size - 1] = '\0';

	if (strcmp(input, "exit") == 0)
	{
		free(input);
		exit(0);
	}

	token = strtok(input, " ");
	i = 0;

	while (token != NULL)
	{
		args[i] = strdup(token); /* ajoute le token au tableau d'argument */
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	free(input);
	return (0);
}

/**
 * execute_command - execute la commande avec ses arguments
 * @args: tableau contenant la commande et ses arguments
 */
void execute_command(char *args[])
{
	pid_t pid = fork();
	int i = 0;

	if (pid == 0)
	{
		char *full_path = find_command(args[0]);

		if (full_path == NULL)
		{
			printf("%s: not found\n", args[0]);
			exit(1);
		}
		if (execve(full_path, args, environ) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else if (pid == -1)
	{
		perror("fork");
	}
	else
	{
		wait(NULL);
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
	}
}

/**
 * main - affiche le prompt à l'utilisateur en attendant une entrée
 * Return: 0
 */
int main(void)
{
	char *args[20];

	while (1)
	{
		if (read_input(args) != 0)
			break;

		execute_command(args);
	}
	return (0);
}
