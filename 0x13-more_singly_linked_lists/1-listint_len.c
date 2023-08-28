#include "lists.h"

/**
 * listint_len - takes a pointer to the head of a linked list as its
 * input parameter
 * @h: pointer to the list_t list to print
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

