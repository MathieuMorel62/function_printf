#include "main.h"

/**
 * get_function - fonction
 * @str: string to print
 * Return: null
 */

int (*get_function(const char *str))(va_list, print_buffer_t *)
{
	int i = 0;
	print_type argument[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_pct},
		{"i", print_int},
		{"d", print_int},
		{"b", convert_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex_lower},
		{"X", print_hex_upper},
		{NULL, NULL}
	};

	while (argument[i].parameter != NULL)
	{
		if (*argument[i].parameter == *str)
			return (argument[i].f);
		i++;
	}
	return (NULL);
}
