#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * _getenv - trouve une ligne précise dans l'environnement
 * @name: la string contenant la ligne a rechercher
 * Return: l'adresse de l'environnement si réussite, NULL autrement
 */

char *_getenv(const char *name)
{
	unsigned int j;
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		j = 0;
		while (name[j] != '\0' && environ[i][j] != '=' && name[j] == environ[i][j])
			j++;

		if (name[j] == '\0' && environ[i][j] == '=')
			return (&environ[i][j + 1]);
		i++;
	}
	return (NULL);
}

/**
 * absolute_command - si le chemin d'une commande est donnée
 * verifie si elle existe puis l'execute
 * @command: la string contenant la commande
 * Return: la commande si elle est valide, NULL sinon
 */
char *absolute_command(const char *command)
{
	int fd;

	if (command[0] == '/' || command[0] == '.')
	{
		fd = open(command, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			return (strdup(command));
		}
	}
	return (NULL);
}
/**
 * find_command - cherche ou se situe la commande demandée puis l'execute
 * @command: la string contenant la commande a chercher
 * Return: le chemin vers la commande, NULL si pas trouvée
 */

char *find_command(const char *command)
{
	char *absolute_path = absolute_command(command);
	char *path = _getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	static char full_path[1024];
	int i, j;

	if (absolute_path != NULL)
		return (absolute_path);

	while (dir != NULL)
	{
		i = 0;
		while (dir[i] != '\0')
		{
			full_path[i] = dir[i];
			i++;
		}
		full_path[i] = '/';
		i++;
		j = 0;
		while (command[j] != '\0')
		{
			full_path[i] = command[j];
			i++;
			j++;
		}
		full_path[i] = '\0';

		if (access(full_path, X_OK) == 0) /* verifie si le fichier est exécutable */
        {
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
