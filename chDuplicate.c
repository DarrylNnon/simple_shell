#include "shell.h"
/**
 * chDuplicate- func doubles chars
 * @pth2str: PATH2string
 * @start: index begins
 * @stop: stop index
 * Return: returns pointr2buffer
 */
char *chDuplicate(char *pth2str, int start, int stop)
{
	static char buf[1024];
	int x = 0;
	int k = 0;

	for (k = 0, x = start; x < stop; x++)
		if (pth2str[x] != ':')
			buf[k++] = pth2str[x];
	buf[k] = 0;
	return (buf);
}
