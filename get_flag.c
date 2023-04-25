#include "main.h"

/**
 * get_flags - extracts the flags from a format string
 * @format: the format string
 * @i: a pointer to an integr holding the current position in the format
 * string
 *
 * the function extracts the flags from a format string and returns them as
 * a flag
 *
 * Return: the flag representing the flags
 */
int get_flags(const char *format, int *i)
{
	int current_index = *i + 1;
	int flags = 0;

	while (format[current_index] != '\0')
	{
		switch (format[current_index])
		{
			case '-':
				flags |= F_MINUS;
				break;
			case '+':
				flags |= F_PLUS;
				break;
			case '0':
				flags |= F_ZERO;
				break;
			case '#':
				flags |= F_HASH;
				break;
			case ' ':
				flags |= F_SPACE;
				break;
			default:
				return (flags);
		}
		current_index++;
	}
	*i = current_index - 1;
	return (flags);
}
