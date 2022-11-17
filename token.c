#include "main.h"

/**
 * token - Tokenize a string
 * @str: String to be tokenized
 *
 * Return: Array of strings
 */

char **token(char *str)
{
	char **arrstr;
	char *delim, *substr;
	int i;

	arrstr = malloc(sizeof(char *) * strlen(str));
	if (arrstr == NULL)
		exit(EXIT_FAILURE);

	delim = " \n";
	substr = strtok(str, delim);
	i = 0;

	while (substr)
	{
		arrstr[i] = substr;
		substr = strtok(NULL, delim);
		i++;
	}
	arrstr[i] = NULL;

	return (arrstr);
}
