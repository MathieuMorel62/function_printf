#include "main.h"

/**
 * print_string - prints a string
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list ap)
{
	int i;
	char *str = va_arg(ap, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}
