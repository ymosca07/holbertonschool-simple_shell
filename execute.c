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
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
		exit(127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror(argv[0]);
		free(full_path);
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
		exit(1);
	}

	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror(argv[0]);
			free(full_path);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}

	free(full_path);
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}