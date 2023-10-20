#include "shell.h"
/**
 * line_geta - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 * getLine.c
 */
int line_geta(info_t *info, char **ptr, size_t *length)
{
	char *p = NULL, *niew_ptr = NULL, *c;
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t z;
	ssize_t r = 0, s = 0;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = input_buffa(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = strngStr(buf + i, '\n');
	z = c ? 1 + (unsigned int)(c - buf) : len;
	niew_ptr = chngAlloc(p, s, s ? s + z : z + 1);
	if (!niew_ptr) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		cat_str(niew_ptr, buf + i, z - i);
	else
		copy_str(niew_ptr, buf + i, z - i + 1);

	s += z - i;
	i = z;
	p = niew_ptr;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sign_handler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 * getLine.c
 */
void sign_handler(__attribute__((unused))int sig_num)
{
	putStrng("\n");
	putStrng("$ ");
	put_caracter(BUF_FLUSH);
}
