#include "main.h"

/**
 * print_char - print a single character
 * @ap: argument list
 * @pb: output buffer
 *
 * Return: number of characters printed, or -1 on error
 */
int print_char(va_list ap, print_buffer_t *pb)
{
	char ch;

	ch = (char)va_arg(ap, int);
	if (pb_putc(pb, ch) < 0)
		return (-1);
	return (1);
}
