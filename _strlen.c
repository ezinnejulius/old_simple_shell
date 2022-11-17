#include "main.h"

/**
 * _strlen - Calculates the length of a string
 * @s: String
 *
 * Return: Length of string
 */

int _strlen(char *s)
{
	int xLength;

	xLength = 0;
	while (s[xLength] != '\0')
	{
		xLength++;
	}

	return (xLength);
}
