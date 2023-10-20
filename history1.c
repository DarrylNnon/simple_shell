#include "shell.h"

/**
 * getHstryFile - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 * Authors: Isaac and Nnon
 */

char *getHstryFile(info_t *info)
{
	char *buf, *dir;

	dir = get_env(info, "HOME=");
	if (!dir)
	{
		return (NULL);
	}
	buf = malloc(sizeof(char) * (striinglent(dir) + striinglent(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	strncoppi(buf, dir);
	strncrtinasion(buf, "/");
	strncrtinasion(buf, HIST_FILE);
	return (buf);
}
/**
 * riteHistry - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 * history.c
 */
int riteHistry(info_t *info)
{
	list_t *node = NULL;
	ssize_t fd;
	char *filename = getHstryFile(info);

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putin(node->str, fd);
		in_puts('\n', fd);
	}
	in_puts(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
