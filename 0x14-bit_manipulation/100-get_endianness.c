#include "main.h"

/**
 * get_endianness - check machine endianness
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *endianness = (char *) &i;

	return (*endianness);
}
