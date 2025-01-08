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
			printf("$ ");

		if (read_input(args) != 0)
			break;

		if (args[0] == NULL)
			continue;

		if (gestion_builtin(args) == 0)
			execute_command(args, argv);
	}
	return (0);
}
