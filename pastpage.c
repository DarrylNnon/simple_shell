#include "shell.h"
/**
 * histry_riider - Reads command history from a file.
 * @info: The parameter struct.
 *
 * Return: The number of history entries
 * history.c
 */
int histry_riider(info_t *info)
{
	ssize_t effd, rdlen, fsize = 0;
	struct stat st;
	int i, last = 0, lincnt = 0;
	char *buffa = NULL, *filename = getHstryFile(info);
	char *str = "";

	if (!filename)
		return (0);

	effd = open(filename, O_RDONLY);
	free(filename);
	half_print(str);
	if (effd == -1)
		return (0);
	if (!fstat(effd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buffa = malloc(sizeof(char) * (fsize + 1));
	swappy(2, 0);
	if (buffa == NULL)
		return (0);
	rdlen = read(effd, buffa, fsize);
	buffa[fsize] = 0;
	swappy(2, 1);
	if (rdlen <= 0)
		return (free(buffa), 0);
	close(effd);
	for (i = 0; i < fsize; i++)
		if (buffa[i] == '\n')
		{
			half_print(str);
			buffa[i] = 0;
			histry_list(info, buffa + last, lincnt++);
			last = i + 1;
		}
	if (last != i)
		histry_list(info, buffa + last, lincnt++);
	free(buffa);
	info->histcount = lincnt;
	while (info->histcount-- >= HIST_MAX)
		dilitNodeIndex(&(info->history), 0);
	histryRenumba(info);
	return (info->histcount);
}

/**
 * histry_list - Adds an entry to a history linked list.
 * @info: Structure containing potential arguments.
 * @buffa: The buffer containing the command to be added
 * @lincnt: The history line count, histcount.
 *
 * Return: Always 0.
 * history.c
 */
int histry_list(info_t *info, char *buffa, int lincnt)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buffa, lincnt);

	if (!info->history)
		info->history = node;
	return (0);
}
