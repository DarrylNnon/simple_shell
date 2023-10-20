#include "shell.h"
/**
 * decimal_pr - function prints a decimal (integer) number (base 10)
 * @input: the user input
 * @fd: is the filedescriptor to write to
 * Return: as specified
 */
int decimal_pr(int input, int fd)
{
	int (*__putchar)(char) = put_caracter;
	int count = 0;
	unsigned int _abs_, current;

	int i = 1000000000;

	if (fd == STDERR_FILENO)
		__putchar = _putcar;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;

	current = _abs_;

	while (i > 1)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
		i /= 10;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * converter - convert function, a clone of itoa
 * @num: is the number input
 * @base: is the base number
 * @flags: argument flags
 * Return: as specified
 */
char *converter(long int num, int base, int flags)
{
	static char *arr;
	static char buff[50];
	char sig = 0;
	char *ptr;
	unsigned long i = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		i = -num;
		sig = '-';

	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[i % base];
		i /= base;
	} while (i != 0);

	if (sig)
		*--ptr = sig;
	return (ptr);
}
