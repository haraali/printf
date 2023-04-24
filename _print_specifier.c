#include "main.h"
#include <stdarg.h>

/**
 * _print_char - print a character
 * @args: va_list containing the arguments
 * Return: void
 */
void _print_char(va_list *args)
{
	int c = va_arg(*args, int);

	_putchar(c);
}

/**
 * _print_string - print a string
 * @args: va_list containing the arguments
 * Return: void
 */
void _print_string(va_list *args)
{
	char *s = va_arg(*args, char*);

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		_putchar(*s);
		s++;
	}
}

/**
 * _print_int - print an integer
 * @args: va_list containing the arguments
 * Return: void
 */
void _print_int(va_list *args)
{
	int n = va_arg(*args, int);
	int sign = 1;

	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}

	if (n / 10)
		_print_int(args);

	_putchar(n % 10 + '0');

	if (sign == -1)
		_putchar('-');
}

/**
 * _print_percent - print a percent symbol
 * @args: va_list containing the arguments
 * Return: void
 */
void _print_percent(va_list *args)
{
	_putchar('%');
}
