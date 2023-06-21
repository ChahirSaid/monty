#include "monty.h"

/**
 * _isdigit - Checks if a string is a digit
 * @c: The string to be checked
 *
 * Description: This function checks if a given string represents a digit.
 *              It verifies if the string is not NULL and consists of valid digits.
 *              The string can also include a negative sign '-' at the beginning.
 *
 * Return: 1 if the string is a digit, 0 otherwise
 */
int _isdigit(char *c)
{
	char *aux = c;

	if (c == NULL)
		return (0);
	if (*aux == '-')
		aux++;

	for (; *aux != '\0'; aux++)
	{
		if ((*aux < '0' || *aux > '9'))
		{
			return (0);
		}
	}
	return (1);
}
