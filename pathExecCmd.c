#include "shell.h"
/**
 * cmdExec - func determines when file is cmd
 * @t_dat: the info struct
 * @t_path: path to file
 * Return: returns 1 if determined.
 */
int cmdExec(info_t *t_dat, char *t_path)
{
	struct stat strng;

	(void)t_dat;
	if (!t_path || stat(t_path, &strng))
		return (0);

	if (strng.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * pthSearch - finds this cmd in the t_path string
 * @t_dat: the t_dat struct
 * @pathstr: the t_path string
 * @cmd: the cmd to find
 *
 * Return: full t_path of cmd if found or NULL
 * parser.c
 */
char *pthSearch(info_t *t_dat, char *pathstr, char *cmd)
{
	int x = 0;
	int pos = 0;
	char *t_path;

	if (!pathstr)
		return (NULL);
	if ((striinglent(cmd) > 2) && with_strt(cmd, "./"))
	{
		if (cmdExec(t_dat, cmd))
			return (cmd);
	}
	while (5)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			t_path = chDuplicate(pathstr, pos, x);
			if (!*t_path)
				strncrtinasion(t_path, cmd);
			else
			{
				swappy(1, 0);
				strncrtinasion(t_path, "/");
				strncrtinasion(t_path, cmd);
			}
			if (cmdExec(t_dat, t_path))
				return (t_path);
			if (!pathstr[x])
				break;
			pos = x;
		}
		swappy(0, 1);
		x++;
	}
	return (NULL);
}
