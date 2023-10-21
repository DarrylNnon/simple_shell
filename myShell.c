#include "shell.h"
/**
 * main - project's entry point
 * @argC: number of args.
 * @argV: arg list.
 * Return: returns 0.
 */
int main(int argC, char **argV)
{
	info_t info[] = { INFO_INIT };
	int deff = 2;
	char *str = "";

	deff = deff + 3;

	if (argC == 2)
	{
		deff = open(argV[1], O_RDONLY);
		if (deff == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				half_print(str);
				_puth(argV[0]);
				_puth(": 0: Can't open ");
				_puth(argV[1]);
				_putcar('\n');
				_putcar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = deff;
	}
	half_print(str);
	populate_env_list(info);
	histry_riider(info);
	main_hsh(info, argV);
	return (EXIT_SUCCESS);
}
