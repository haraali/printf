#include "main.h"

/**
 * get_width - extracts the width of a field from a format string
 * @format: the format string
 * @i: a pointer to an integer holding the current position in the format
 * string
 * @list: arguments to be printed
 *
 * this function extracts the width of a format string and returns it as an
 * integer
 *
 * Return: the width of the field or 0 if there's no width specified
 */
int get_width(const char *format, const int *i, va_list list)
{
	int current_index = *i + 1;
	int width = 0;

	while (format[current_index] != '\0')
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(list, int);
			return (width);
		}
		else
		{
			return (width);
		}
		current_index++;
	}
	return (width);
	*i = current_index - 1;
}
