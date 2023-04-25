#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"


void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf -  function that produces output according to a format
 * @format: input value
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i;

	printed = 0;
	printed_chars = 0;
	buff_ind = 0;

	int flags;
	int width;
	int size;
	int precision;

	va_list list;

	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	i = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
		buffer[buff_ind++] = format[i];
		if (buff_ind == BUFF_SIZE)
			print_buffer(buffer, &buff_ind);
		write(1, &format[i], 1);
		printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			size = get_size(format, &i);
			precision = get_precision(format, &i, list);
			++i;
			printed = handle_print(format, &i, list, buffer);
			printed = handle_print(flags, width, size, precision);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
		i++;
	}

	printed_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - prints contents of buffer if it exists
 * @buffer: input value
 * @buff_ind: input value
 * Return: 0
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind <= 0)
		return;

	ssize_t num_written = write(1, buffer, *buff_ind);

	if (num_written < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	else if (num_written < *buff_ind)
	{
		int remaining = *buff_ind - num_written;

		memmove(buffer, buffer + num_written, remaining);
	}

	*buff_ind = 0;
}
