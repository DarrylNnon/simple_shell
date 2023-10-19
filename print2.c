#include <stdio.h>
#include <stdarg.h>
/**
 * printu - Variadic function for formatted printing
 * to the standard output (stdout)
 * @format: is the pointer to the input
 * Authors: Nnon && Isaac
 */
void printu(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

