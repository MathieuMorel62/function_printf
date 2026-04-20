#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * print_samples_part1 - first half of _printf vs printf checks
 */
static void print_samples_part1(void)
{
	int len;
	int len2;
	unsigned int ui;

	printf("--------------------------------------------------------\n");
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("--------------------------------------------------------\n");
	ui = (unsigned int)INT_MAX + 1024;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	printf("--------------------------------------------------------\n");
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	printf("--------------------------------------------------------\n");
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	printf("--------------------------------------------------------\n");
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	printf("--------------------------------------------------------\n");
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
}

/**
 * print_samples_part2 - second half of _printf vs printf checks
 */
static void print_samples_part2(void)
{
	int len;
	int len2;
	void *addr;

	addr = (void *)0x7ffe637541f0;
	printf("--------------------------------------------------------\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	printf("--------------------------------------------------------\n");
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	printf("--------------------------------------------------------\n");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	printf("--------------------------------------------------------\n");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	printf("--------------------------------------------------------\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	printf("--------------------------------------------------------\n");
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	print_samples_part1();
	print_samples_part2();
	return (0);
}
