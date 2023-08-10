#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERR_MSG "Error"

/**
 * check_digit - checks if a string contains only digits
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit character is found, 1 otherwise
 */
int check_digit(char *string)
{
	int index = 0;

	while (string[index])
	{
		if (string[index] < '0' || string[index] > '9')
			return (0);
		index++;
	}
	return (1);
}

/**
 * get_str_length - calculates the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int get_str_length(char *string)
{
	int index = 0;

	while (string[index] != '\0')
	{
		index++;
	}
	return (index);
}

/**
 * handle_errors - handles errors for the main function
 */
void handle_errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *str1, *str2;
	int len1, len2, total_len, i, carry, digit1, digit2, *result, a = 0;

	str1 = argv[1], str2 = argv[2];
	if (argc != 3 || !check_digit(str1) || !check_digit(str2))
		handle_errors();
	len1 = get_str_length(str1);
	len2 = get_str_length(str2);
	total_len = len1 + len2 + 1;
	result = malloc(sizeof(int) * total_len);
	if (!result)
		return (1);
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = str1[len1] - '0';
		carry = 0;
		for (len2 = get_str_length(str2) - 1; len2 >= 0; len2--)
		{
			digit2 = str2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
	for (i = 0; i < total_len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
