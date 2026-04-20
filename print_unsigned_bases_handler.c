#include "main.h"

/**
 * print_unsigned - print unsigned int
 * @ap: argument list
 * @pb: output buffer
 *
 * Return: number of characters printed, or -1 on error
 */
int print_unsigned(va_list ap, print_buffer_t *pb)
{
	unsigned int n;
	unsigned int divisor;
	unsigned int digit;
	int result;

	n = va_arg(ap, unsigned int);
	divisor = 1;
	result = 0;

	if (n == 0)
	{
		if (pb_putc(pb, '0') < 0)
			return (-1);
		return (1);
	}

	while ((n / divisor) > 9)
		divisor = divisor * 10;

	while (divisor != 0)
	{
		digit = n / divisor;
		if (pb_putc(pb, (char)(digit + '0')) < 0)
			return (-1);
		result = result + 1;
		n = n % divisor;
		divisor = divisor / 10;
	}

	return (result);
}


/**
 * print_octal - print unsigned int in octal
 * @ap: argument list
 * @pb: output buffer
 *
 * Return: number of characters printed, or -1 on error
 */
int print_octal(va_list ap, print_buffer_t *pb)
{
	unsigned int n;
	char buf[32];
	int i;
	int len;

	n = va_arg(ap, unsigned int);
	i = 0;
	len = 0;

	if (n == 0)
	{
		if (pb_putc(pb, '0') < 0)
			return (-1);
		return (1);
	}

	while (n != 0)
	{
		buf[i] = (char)((n % 8) + '0');
		n = n / 8;
		i = i + 1;
	}

	while (i > 0)
	{
		i = i - 1;
		if (pb_putc(pb, buf[i]) < 0)
			return (-1);
		len = len + 1;
	}

	return (len);
}

/**
 * print_hex - print unsigned int in hexadecimal
 * @ap: argument list
 * @digits: symbols used for conversion
 * @pb: output buffer
 *
 * Return: number of characters printed, or -1 on error
 */
static int print_hex(va_list ap, const char *digits, print_buffer_t *pb)
{
	unsigned int n;
	char buf[16];
	int i;
	int len;

	n = va_arg(ap, unsigned int);
	i = 0;
	len = 0;

	if (n == 0)
	{
		if (pb_putc(pb, '0') < 0)
			return (-1);
		return (1);
	}

	while (n != 0)
	{
		buf[i] = digits[n % 16];
		n = n / 16;
		i = i + 1;
	}

	while (i > 0)
	{
		i = i - 1;
		if (pb_putc(pb, buf[i]) < 0)
			return (-1);
		len = len + 1;
	}

	return (len);
}

/**
 * print_hex_lower - print unsigned int in hexadecimal lowercase
 * @ap: argument list
 * @pb: output buffer
 *
 * Return: number of characters printed, or -1 on error
 */
int print_hex_lower(va_list ap, print_buffer_t *pb)
{
	return (print_hex(ap, "0123456789abcdef", pb));
}

/**
 * print_hex_upper - print unsigned int in hexadecimal uppercase
 * @ap: argument list
 * @pb: output buffer
 *
 * Return: number of characters printed, or -1 on error
 */
int print_hex_upper(va_list ap, print_buffer_t *pb)
{
	return (print_hex(ap, "0123456789ABCDEF", pb));
}
