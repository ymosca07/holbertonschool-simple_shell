#include "shell.h"

/**
 * _strcmp - fonction pour comparer deux strings
 * @s1: premiere string a comparer
 * @s2: deuxieme string a comparer
 *
 * Return: la comparaison des deux strings, 0 si les deux sont similaire
 */

int _strcmp(char *s1, char *s2)
{
	int i;

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
