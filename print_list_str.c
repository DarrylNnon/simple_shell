#include "shell.h"

/**
 * prnt_lstStrng - Prints "str" element of a linked list.
 * @h: Pointer to the first node of the linked list.
 *
 * Return: The size of the linked list.
 * Authors: Isaac and Nnon
 */
size_t prnt_lstStrng(const list_t *h)
{
	size_t i;

	i = 0;
	while (h)
	{
		putStrng(h->str ? h->str : "(nil)");
		putStrng("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * dilitNodeIndex - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 * Authors: Isaac and Nnon
 */
int dilitNodeIndex(list_t **head, unsigned int index)
{
	unsigned int i = 0;
	list_t *node, *prev_node;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	for (i = 0; node; i++)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		prev_node = node;
		node = node->next;
	}
	return (0);
}
