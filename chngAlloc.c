#include "shell.h"
/**
 **fillMryWithByte - func sets up the mry memory with byte
 *@st: memory area
 *@charr: char to be used
 *@n: the amount.
 *Return: returns st
 */
char *fillMryWithByte(char *st, char charr, unsigned int n)
{
	unsigned int x;

	x = 0;
	while (x < n)
	{
		st[x] = charr;
		x++;
	}
	return (st);
}
/**
 * chngAlloc - func changes block of memory allocation
 * @ptr: points to prev block
 * @prev_s: size of prev block
 * @new_s: size of new block
 * Return: pointr to blk is returned.
 */
void *chngAlloc(void *ptr, unsigned int prev_s, unsigned int new_s)
{
	char *p;

	if (ptr == NULL)
	{
		return (malloc(new_s));
	}
	if (!new_s)
		return (free(ptr), NULL);
	if (new_s == prev_s)
		return (ptr);

	p = malloc(new_s);
	if (!p)
		return (NULL);

	prev_s = prev_s < new_s ? prev_s : new_s;
	while (prev_s--)
		p[prev_s] = ((char *)ptr)[prev_s];
	free(ptr);
	return (p);
}
