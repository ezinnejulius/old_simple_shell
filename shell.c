#include "main.h"
#include "token.c"

/**
 * main - Simple Shell
 *
 * Return: Always 0.
 */

int main(void)
{
	char *prompt, *line;
	char **command;
	size_t len;
	ssize_t numRead;
	pid_t child;
	int status;

	prompt = "#cisfun$ ";
	line = NULL;
	len = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		numRead = getline(&line, &len, stdin);
		if (numRead == -1)
			exit(EXIT_FAILURE);

		command = token(line);

		child = fork();
		if (child == 0)
		{
			if (execve(command[0], command, NULL) == -1)
				perror("execve");
		}
		else
		{
			wait(&status);
		}

		free(command);
		free(line);
	}

	return (0);
}
