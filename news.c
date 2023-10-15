#include "main.h"

/**
 * times_table - Prints the 9 times table
 *
 * Return: no return
 * Author: Darryl Nnon
 */
void times_table(void)
{
	int e, f, xy;

	for (e = 0; e <= 9; e++)
	{
		_putchar(48);
		for (f = 1; f <= 9; f++)
		{
			xy = e * f;
			_putchar(44);
			_putchar(32);
			if (xy <= 9)
			{
				_putchar(32);
				_putchar(xy + 48);
			}
			else
			{
				_putchar((xy / 10) + 48);
				_putchar((xy % 10) + 48);
			}
		}
		_putchar('\n');
	}
}
