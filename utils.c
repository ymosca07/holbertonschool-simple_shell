#include "shell.h"

/**
 * _strdup - duplique une string
 * @str: la string a dupliquer
 * Return: NULL si la string est vide, la copie autrement
 */
char *_strdup(const char *str)
{
	char *copy;
	size_t len = 0;
	size_t i;

	if (str == NULL)
		return (NULL);

	/* calcul la longueur de la string */
	while (str[len] != '\0')
		len++;

	/* alloue de la memoire +1 pour le nul byte */
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	/* Copier chaque caractère dans la nouvelle zone */
	for (i = 0; i <= len; i++)
		copy[i] = str[i];

	return (copy);
}

/**
 * _strcmp - fonction pour comparer deux strings
 * @s1: premiere string a comparer
 * @s2: deuxieme string a comparer
 * Return: la comparaison des deux strings, 0 si les deux sont similaire
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	/* la boucle se fini a la fin d'une string */
	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		/* si un caractere est different */
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

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
