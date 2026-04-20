#include "main.h"

/**
 * print_pct - prints the '%' character
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_pct(va_list ap __attribute__((unused)))
{
	_putchar('%');
	return (1);
}
