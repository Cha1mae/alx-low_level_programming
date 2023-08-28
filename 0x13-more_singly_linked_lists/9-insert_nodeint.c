#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int index_variable;
	listint_t *added_node;
	listint_t *temp = *head;

	added_node = malloc(sizeof(listint_t));
	if (!added_node || !head)
		return (NULL);

	added_node->n = n;
	added_node->next = NULL;

	if (idx == 0)
	{
		added_node->next = *head;
		*head = added_node;
		return (added_node);
	}

	for (index_variable = 0; temp && index_variable < idx; index_variable++)
	{
		if (index_variable == idx - 1)
		{
			added_node->next = temp->next;
			temp->next = added_node;
			return (added_node);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
