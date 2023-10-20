#include "shell.h"

/**
 * error_atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: as specified
 */
int error_atoi(char *s)
{
	int i = 0;
	unsigned long int output = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			output *= 10;
			output += (s[i] - '0');
			if (output > INT_MAX)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (output);
}
/**
 * error_print - is used to print error message
 * @info: the parameter & return info struct
 * @error: is the pointer str containing error type
 * Return: as specified
 */
void error_print(info_t *info, char *error)
{
	_puth(info->fname);
	_puth(": ");
	decimal_pr(info->line_count, STDERR_FILENO);
	_puth(": ");
	_puth(info->argv[0]);
	_puth(": ");
	_puth(error);
}
