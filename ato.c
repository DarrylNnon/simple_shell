#include "shell.h"
/**
 * alpha - is function to check for alphabet char
 * @i: is the character input
 * Return: as specified
 *_atoic.c
 */

int alpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * custom_atoi - is a func that convert a str to an int
 * @s: the string to be converted
 * Return: as specified
 *_atoic.c
 */
int custom_atoi(char *s)
{
	int i = 0, sign = 1, flag = 0, output;
	unsigned int result = 0;

	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		}
		i++;
	}
	if (sign == -1)
	output = -result;
	else
		output = result;
	return (output);
}

