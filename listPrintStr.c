#include "shell.h"
/**
 * listStrs - func gets array of strings of list
 * @h: address of nd
 * Return: returns array of str
 */
char **listStrs(list_t *h)
{
	list_t *nd;
	size_t x, j;
	char **strPtr;
	char *str;

	x = listLen(h);
	nd = h;
	if (!h || !x)
		return (NULL);
	strPtr = malloc(sizeof(char *) * (x + 1));
	if (!strPtr)
		return (NULL);
	for (x = 0; nd; nd = nd->next, x++)
	{
		str = malloc(striinglent(nd->str) + 1);
		if (!str)
		{
			for (j = 0; j < x; j++)
				free(strPtr[j]);
			free(strPtr);
			return (NULL);
		}
		str = strncoppi(str, nd->str);
		strPtr[x] = str;
	}
	strPtr[x] = NULL;
	return (strPtr);
}

/**
 * dispList - func displays every element of list
 * @h: pt to first node
 * Return: size of list is returned
 */
size_t dispList(const list_t *h)
{
	size_t x = 0;

	while (h != NULL)
	{
		putStrng(converter(h->num, 10, 0));
		put_caracter(':');
		put_caracter(' ');
		putStrng(h->str ? h->str : "(nil)");
		putStrng("\n");
		h = h->next;
		x++;
	}
	return (x);
}
