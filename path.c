#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * create_node - a new node with given data.
 * @data: the function allocate memory for a new mode.
 * Authors: Nnon && Isaac
 * Return: A pointer to the newly created node
 */
Node *create_node(char *data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Out of memory\n");
		exit(1);
	}
	new_node->data = strdup(data);
	if (new_node->data == NULL)
	{
		fprintf(stderr, "Error: Out of memory\n");
		exit(1);
	}
	new_node->next = NULL;
		return (new_node);
}
/**
 * build_path_list - is used to build the path ls
 * Return: as specified
 */
Node *build_path_list(void)
{
	char *path = getenv("PATH");
	char *start = path;
	char *end = strchr(start, ':');
	Node *head = NULL;
	Node *current = NULL;
	Node *new_node = create_node(start);

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		return (NULL);
	}

	path = strdup(path);
	if (path == NULL)
	{
		fprintf(stderr, "Error: Out of memory\n");
		return (NULL);
	}

	while (end != NULL)
	{
		*end = '\0';
	if (head == NULL)
	{
		head = new_node;
		current = head;
	}
	else
	{
		current->next = new_node;
		current = current->next;
	}
		start = end + 1;
		end = strchr(start, ':');
	}
	current->next = create_node(start);

	free(path);
	return (head);
}
/**
 * print_list - is used to print ls
 * @head: is the pointer
 * Return: as specified
 */
void print_list(Node *head)
{
	Node *current = head;

	while (current != NULL)
	{
		printu("%s\n", STDOUT_FILENO, current->data);
		current = current->next;
	}
}

