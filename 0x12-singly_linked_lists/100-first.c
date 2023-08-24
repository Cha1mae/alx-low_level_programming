#include <stdio.h>

void before_main_function(void) __attribute__ ((constructor));

/**
 * before_main_function - prints a sentence before the main function,
 * is executed
 */
void before_main_function(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
