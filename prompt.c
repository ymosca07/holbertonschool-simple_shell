#include "shell.h"

/**
 * main - affiche le prompt à l'utilisateur en attendant une entrée
 * @argc: compteur d'arguments
 * @argv: tableau contenant les arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *args[1024];
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		if (read_input(args) != 0)
			break;
		execute_command(args, argv);
	}
	return (0);
}

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

	read_size = getline(&input, &input_size, stdin);

	if (read_size == -1) /* vérifier EOF ou erreur */
	{
		if (isatty(STDIN_FILENO))
			printf("\n");
		free(input);
		exit(0);
	}

	if (read_size == 0)
	{
		free(input);
		exit(0);
	}
	if (input[read_size - 1] == '\n')
		input[read_size - 1] = '\0';

	token = strtok(input, " ");
	i = 0;

	while (token != NULL)
	{
		args[i] = _strdup(token); /* ajoute le token au tableau d'argument */
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
 * @argv: tableau contenant les arguments d'execution du fichier
 */
void execute_command(char *args[], char *argv[])
{
	pid_t pid;
	int i = 0;
	char *full_path;

	if (_strcmp(args[0], "exit") == 0)
		exit(0);
	if (args[0] == NULL)
		return;
	full_path = find_command(args[0]);
	if (full_path == NULL)
	{
		perror(argv[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else if (pid == -1)
		perror("fork");
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
