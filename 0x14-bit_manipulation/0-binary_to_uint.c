#include "main.h"

/**
 * binary_to_uint - converts a binary number to unit
 * @b: binary string
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int converted_number = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		converted_number = 2 * converted_number + (b[i] - '0');
	}

	return (converted_number);
}
