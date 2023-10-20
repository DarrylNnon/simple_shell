#include "shell.h"
/**
 * listLen - func checks for width of  list
 * @h: pointr2first member
 * Return: width of list is returned
 * Authors: Isaac and Nnon
 */
size_t listLen(const list_t *h)
{
	size_t x = 0;

	while (h != NULL)
	{
		h = h->next;
		x++;
	}
	return (x);
}
