#include "shell.h"

/**
 * writeBuffa - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 * Authors: Isaac and Nnon
 */
ssize_t writeBuffa(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sign_handler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = line_geta(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			rem_comment(*buf);
			histry_list(info, *buf, info->histcount++);
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * input_buffa - Reads input into a buffer.
 * @info: Parameter struct.
 * @buf: Buffer to store input.
 * @i: Size of the buffer.
 *
 * Return: The number of bytes read (r).
 * getLine.c
 */
ssize_t input_buffa(info_t *info, char *buf, size_t *i)
{
	ssize_t r;

	r = 0;
	if (*i)
	{
		return (0);
		}
		r = read(info->readfd, buf, READ_BUF_SIZE);
		if (r >= 0)
		{
			*i = r;
		}
		return (r);
}
