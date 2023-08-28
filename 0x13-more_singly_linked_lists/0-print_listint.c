#include "lists.h"

/**
 * print_listint - function takes a pointer to the head of a linked list as its
 * input parameter
 * @h: pointer to the list_t list to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		i++;
		h = h->next;
	}

	return (i);
}
