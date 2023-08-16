#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - prints a name using a function pointer
 * @name: string to print
 * @f: pointer to the function that prints the name
 * Return: nothing
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
