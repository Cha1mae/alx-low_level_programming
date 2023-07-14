#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase and uppercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 97;
	int N = 65;

	while (n <= 122)
	{
		putchar(n);
		n++;
	}

	while (N <= 90)
	{
		putchar(N);
		N++;
	}

	putchar('\n');

	return (0);
}
