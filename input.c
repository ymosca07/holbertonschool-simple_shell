#include "shell.h"

/**
 * read_input - lit l'entrée de l'utilisateur
 * et sépare la commande des arguments
 * @args: tableau pour stocker les arguments séparés
 * Return: 0 si réussite, 1 si échec
 */
int read_input(char *args[])
{
	char *token, *input = NULL;
	size_t input_size = 0;
	ssize_t read_size;
	int i;

	read_size = getline(&input, &input_size, stdin);

	if (read_size == -1)
	{
		if (isatty(STDIN_FILENO))
			printf("\n");
		free(input);
		exit(0);
	}

	if (input[0] == '\n')
	{
		free(input);
		args[0] = NULL;
		return (0);
	}

	if (input[read_size - 1] == '\n')
		input[read_size - 1] = '\0';

	token = strtok(input, " ");

	if (token == NULL)
		return(NULL);

	i = 0;

	while (token != NULL)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	free(input);
	return (0);
}
