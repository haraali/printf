#include "main.h"

/**
 * get_size - extracts the size of a variable modifier from a format string
 * @format: the format string
 * @i: a pointer to an integer holding the current position in the format
 * string
 *
 * this function extracts the size of a variable modifier ('l' or 'h')
 * from a format string and returns it as an integer
 *
 * Return: the size of the variable modifier or 0 is there's no modifier
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
