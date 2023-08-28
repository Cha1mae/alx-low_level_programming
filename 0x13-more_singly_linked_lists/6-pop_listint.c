#include "lists.h"

/**
 * pop_listint - deletes head node of the linked list
 * @head: pointer to the first element in the linked list
 *
 * Return: the data inside the elements that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int head_data;

	if (!head || !*head)
		return (0);

	head_data = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (head_data);
}
