#include "main.h"
#include "_strlen.c"

/**
 * main - Simple Shell
 * @ac: Argument count
 * @av: Argument vector (array of arguments)
 * @env: Environment variable
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	/* extern char **environ; */
	char *prompt, *line, *msg, *delim, *substr;
	char **command;
	size_t len;
	ssize_t numRead;
	pid_t child;
	int status, i;

	(void) ac;
	prompt = "#cisfun$ ";
	line = NULL;
	delim = "\n";
	len = 0;

	/* while (isatty(STDIN_FILENO) == 1) */
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		numRead = getline(&line, &len, stdin);
		if (numRead == -1)
			_exit(status);

		command = malloc(sizeof(char *) * numRead);
		if (command == NULL)
			_exit(status);

		substr = strtok(line, delim);
		i = 0;
		while (substr)
		{
			command[i] = substr;
			substr = strtok(NULL, delim);
			i++;
		}
		command[i] = NULL;

		child = fork();
		if (child == 0)
		{
			if (execve(command[0], command, env) == -1)
			{
				msg = av[0];
				perror(msg);
			}
		}
		else
		{
			wait(&status);
		}
		free(command);
	}

	free(line);
	return (0);
}
