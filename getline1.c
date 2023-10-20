#include "shell.h"

/**
 * write_input - Gets a line of input, excluding the newline character.
 * @info: Parameter struct.
 *
 * Return: The number of bytes read.
 * getLine.c
 */
ssize_t write_input(info_t *info)
{
	static char *buffa;
	static size_t x, j, leintt;
	ssize_t r = 0;
	char **buffa_ptr = &(info->arg), *p;

	put_caracter(BUF_FLUSH);
	r = writeBuffa(info, &buffa, &leintt);
	if (r == -1)
		return (-1);
	if (leintt)
	{
		j = x;
		p = buffa + x;

		check_chain(info, buffa, &j, x, leintt);
		while (j < leintt)
		{
			if (is_chain(info, buffa, &j))
				break;
			j++;
		}

		x = j + 1;
		if (x >= leintt)
		{
			x = leintt = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buffa_ptr = p;
		return (striinglent(p));
	}

	*buffa_ptr = buffa;
	return (r);
}

