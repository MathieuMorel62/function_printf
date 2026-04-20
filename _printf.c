#include "main.h"

/**
 * apply_specifier - handle a '%' conversion starting at *pi
 * @format: format string
 * @pi: index of '%'; updated after processing
 * @plen: running length; updated
 * @ap: variadic arguments
 * @pb: output buffer
 *
 * Return: 0 on success, -1 on I/O error, -2 if format ends after '%'
 */
static int apply_specifier(const char *format, int *pi, int *plen,
		va_list ap, print_buffer_t *pb)
{
	int i = *pi;
	int len = *plen;
	int r;
	int (*func)(va_list ap, print_buffer_t *pb);

	if (format[i + 1] == '\0')
		return (-2);
	i = i + 1;
	if (format[i] != '\0')
	{
		func = get_function(format + i);
		i = i + 1;
	}
	else
		func = NULL;
	if (func == NULL)
	{
		if (pb_putc(pb, '%') < 0)
			return (-1);
		len = len + 1;
		if (pb_putc(pb, format[i - 1]) < 0)
			return (-1);
		len = len + 1;
	}
	else
	{
		r = func(ap, pb);
		if (r < 0)
			return (-1);
		len = len + r;
	}
	*pi = i;
	*plen = len;
	return (0);
}

/**
 * _printf - function printf
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int len = 0;
	int r;
	va_list ap;
	print_buffer_t pb;

	pb.used = 0;
	va_start(ap, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		va_end(ap);
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			r = apply_specifier(format, &i, &len, ap, &pb);
			if (r == -2 || r < 0)
			{
				(void)pb_flush(&pb);
				va_end(ap);
				return (-1);
			}
		}
		else
		{
			if (pb_putc(&pb, format[i]) < 0)
			{
				(void)pb_flush(&pb);
				va_end(ap);
				return (-1);
			}
			len = len + 1;
			i = i + 1;
		}
	}
	if (pb_flush(&pb) < 0)
	{
		va_end(ap);
		return (-1);
	}
	va_end(ap);
	return (len);
}
