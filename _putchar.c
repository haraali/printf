#include <unistd.h>

/**
 * _putchar - writes a character to the stardard output
 * @c: character to be printed
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
