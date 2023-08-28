#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *deleted_node = NULL;
	unsigned int index_variable = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (index_variable < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		index_variable++;
	}


	deleted_node = temp->next;
	temp->next = deleted_node->next;
	free(deleted_node);

	return (1);
}
