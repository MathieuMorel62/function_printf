#include "main.h"

/**
 * print_string - prints a string
 * @ap: argument list
 * @pb: output buffer
 *
 * Return: number of characters printed, or -1 on error
 */
int print_string(va_list ap, print_buffer_t *pb)
{
	int index;
	int count;
	char *str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";

	count = 0;
	for (index = 0; str[index] != '\0'; index = index + 1)
	{
		if (pb_putc(pb, str[index]) < 0)
			return (-1);
		count = count + 1;
	}

	return (count);
}
