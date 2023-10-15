#include <stdio.h>

/**
 * main - Prints the add of the Fibonacci numbers
 *
 * Return: Always 0.
 * Author: DarrylNnon
 */
int main(void)
{
	int a;
	long int e1, e2, fn;

	e1 = 1;
	e2 = 2;
	printf("%ld, %ld", e1, e2);
	for (a = 0; a < 48; a++)
	{
		fn = e1 + e2;
		printf(", %ld", fn);
		e1 = e2;
		e2 = fn;
	}
	printf("\n");
	return (0);
}
