#include "lists.h"

/**
 * sum_dlistint - Returns the sum of n
 * @head: A pointer to the head
 * Return: The sum of all the data, or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int d_sum = 0;

	while (head != NULL)
	{
		d_sum += head->n;
		head = head->next;
	}

	return (d_sum);
}
