#include "main.h"

/**
 * _strlen - Calculates the lenght of a string
 *@s: String
 *
 * Return: Lenghth of string
 */

int _strlen(char *s)
{
	int xLength;

	xLength = 0;
	while (s[xLength] != '\0')
	{
		xLenghth++;
	}
	
	return (xLength);
}
