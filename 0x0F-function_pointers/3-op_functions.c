#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - Adds two numbers
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub -  Subtracts two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The subtraction of a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - Multiply two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The multiplication of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - Divide two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The dividing of a and b.
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - Computes two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The remainder of deviding of a by b.
 */
int op_mod(int a, int b)
{
	return (a % b);
}
