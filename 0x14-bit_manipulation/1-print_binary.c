#include "main.h"

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: the decimal number to print
 */
void print_binary(unsigned long int n)
{
	int i, bit_counter = 0;
	unsigned long int value;

	for (i = 63; i >= 0; i--)
	{
		value = n >> i;

		if (value & 1)
		{
			_putchar('1');
			bit_counter++;
		}
		else if (bit_counter)
			_putchar('0');
	}
	if (!bit_counter)
		_putchar('0');
}
