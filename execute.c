#include "shell.h"

/**
 * execute_command - Execute une commande avec ses arguments
 * @args: Tableau contenant la commande et ses arguments
 * @argv: Tableau contenant les arguments d'execution
 */

void execute_command(char *args[], char *argv[])
{
	pid_t pid;
	int i = 0;
	char *full_path = find_command(args[0]);

	if (full_path == NULL)
	{
		perror(args[0]);
		while (args[i] != NULL)
			free(args[i++]);
		exit(127);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(argv[0]);
		free(full_path);
		while (args[i] != NULL)
			free(args[i++]);
		exit(1);
	}
	if (pid == 0) /* Processus enfant */
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror(argv[0]);
			free(full_path);
			while (args[i])
				free(args[i++]);
			exit(1);
		}
	}
	else /* Processus parent */
	{
		wait(NULL);
		while (args[i] != NULL)
			free(args[i++]);
	}
	free(full_path);
	free(args);
}
