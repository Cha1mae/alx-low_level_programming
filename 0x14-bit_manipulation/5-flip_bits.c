#include "main.h"

/**
 * flip_bits - count bits needed to change between two numbers
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, bit_counter = 0;
	unsigned long int value;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		value = exclusive >> i;
		if (value & 1)
			bit_counter++;
	}

	return (bit_counter);
}
