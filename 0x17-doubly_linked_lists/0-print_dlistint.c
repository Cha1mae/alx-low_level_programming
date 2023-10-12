#include "lists.h"

/**
 * print_dlistint - Prints delements of dlistint_t list
 * @head: A pointer to the head
 * Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *head)
{
	size_t d_num = 0;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		d_num++;
	}

	return (d_num);
}
