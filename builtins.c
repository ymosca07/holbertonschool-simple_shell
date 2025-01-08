#include "shell.h"

/**
 * gestion_builtin - gère les commandes intégrées
 * @args: tableau d'arguments de la commande
 * Return: 1 si une commande builtin a été exécutée, 0 sinon
 */
int gestion_builtin(char **args)
{
	int i = 0;

	if (args == NULL || args[0] == NULL)
		return (0);

	if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		exit(0);
	}

	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

/**
 * print_env - affiche les variables d'environnement
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
