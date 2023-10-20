#include "shell.h"
/**
 * beginNodeWith - func traces begining with pre
 * @dd: pointr2list
 * @pre: matching str
 * @c: next character after
 * Return: returns match
 */
list_t *beginNodeWith(list_t *dd, char *pre, char c)
{
	char *p;

	p = NULL;
	while (dd != NULL)
	{
		p = with_strt(dd->str, pre);
		if (p && ((c == -1) || (*p == c)))
			return (dd);
		dd = dd->next;
	}
	return (NULL);
}
/**
 * fetchIdx - fetch dd
 * @head: pointr2head
 * @dd: pointr2dd
 * Return: index is returned
 */
ssize_t fetchIdx(list_t *head, list_t *dd)
{
	size_t x = 0;

	while (head != NULL)
	{
		if (head == dd)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}
