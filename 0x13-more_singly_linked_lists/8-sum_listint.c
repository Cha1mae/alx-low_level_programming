#include "lists.h"

/**
 * sum_listint - calculates the sum the data in a listint_t list
 * @head: first node in the linked list
 *
 * Return: resulting sum
 */
int sum_listint(listint_t *head)
{
	int data_sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		data_sum += temp->n;
		temp = temp->next;
	}

	return (data_sum);
}
