#include "shell.h"

/**
 * absolute_command - vérifie si le chemin donné est valide
 * @command: la commande à vérifier
 * Return: la commande si valide, NULL sinon
 */
char *absolute_command(const char *command)
{
	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, X_OK) == 0)
			return (_strdup(command));
	}
	return (NULL);
}

/**
 * build_path - construit le chemin complet d'une commande
 * @dir: le répertoire
 * @command: la commande
 * @full_path: string pour stocker le chemin complet
 */
void build_path(char *dir, const char *command, char *full_path)
{
	int i = 0, j = 0;

	while (dir[i] != '\0')
	{
		full_path[i] = dir[i];
		i++;
	}
	full_path[i] = '/';
	i++;
	while (command[j] != '\0')
	{
		full_path[i] = command[j];
		i++, j++;
	}
	full_path[i] = '\0';
}

/**
 * find_command - cherche ou se trouve la commande demandée
 * @command: la commande a chercher
 * Return: le chemin vers la commande, NULL si pas trouvée
 */
char *find_command(const char *command)
{
	char *absolute_path, *path, *path_copy, *dir;
	static char full_path[1024];

	absolute_path = absolute_command(command);
	if (absolute_path != NULL)
		return (absolute_path);

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");

	if (dir == NULL)
		return (NULL);

	while (dir != NULL)
	{
		build_path(dir, command, full_path);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
