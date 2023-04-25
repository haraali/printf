#include "main.h"

/**
 * handle_unknown - handles format characters thar are unknown
 * @fmt: input value
 * @ind: input value
 * @c: input value
 * Return: 0
 */
int handle_unknown(const char *fmt, int *ind, char c)
{
	int unknow_len = 0;

	if (fmt[*ind - 1] == ' ')
		unknow_len += write(1, " ", 1);
	else if (width)
	{
		--(*ind);
		while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			--(*ind);
		if (fmt[*ind] == ' ')
			--(*ind);
		return (1);
	}
	unknow_len += write(1, &c, 1);
	return (unknow_len);
}

/**
 * handle_print - prints an argument based on its type
 * @fmt: formatted string in which to print the argument
 * @ind: pointer to index of current character in the format string
 * @list: lists of arguments to be printed
 * @buffer: buffer array to handle print
 * @flags: bitmask of active flags
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 * Return: the number of characters printed or -1 if an error
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		return (handle_unknown(fmt, ind, fmt[*ind]));
	}
	return (printed_chars);
}

