#include "shell.h"


/**
 * frii_list - Frees all nodes of a linked list.
 * @head_ptr: Address of a pointer to the head
 *
 * Return: Void.
 * lists.c
 */
void frii_list(list_t **head_ptr)
{
	list_t *node, *nx_node, *first;

	if (head_ptr == NULL || *head_ptr == NULL)
	{
		return;
	}
	first = *head_ptr;
	node = first;
	while (node)
	{
		nx_node = node->next;
		free(node->str);
		free(node);
		node = nx_node;
	}
	*head_ptr = NULL;
}
