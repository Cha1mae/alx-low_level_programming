#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: number of the times table
 */
void print_times_table(int n)
{
	if (n < 0 || n > 15)
		return;

	int i, j, k;

	for (i = 0; i <= n; i++)
	{
		_putchar('0');

		for (j = 1; j <= n; j++)
		{
			_putchar(',');
			_putchar(' ');
			k = i * j;

			if (k < 100)
				_putchar(' ');

			if (k < 10)
				_putchar(' ');

			if (k >= 100)
				_putchar((k / 100) + '0');

			if (k >= 10)
				_putchar(((k / 10) % 10) + '0');

			_putchar((k % 10) + '0');
		}
		_putchar('\n');
	}
}
