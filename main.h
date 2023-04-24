#ifndef MAIN_H
#define MAIN_H

/**
 * struct convert - a struct type that has a char and function pointer member
 * @specifier: represents the conversion specifier character (c,s,%,d,i)
 * @func: a function pointer to a function which handles the a specifier.
 * Description: a struct that associates conversion specifier characters \
 with corresponding handler functions
 */
struct convert
{
	char specifier;
	int (*func)(va_list *);
};
typedef convert covert_specifier


int _printf(const char *format, ...);
void _print_char(va_list *args);
void _print_string(va_list *args);
void _print_int(va_list *args);
void _print_percent(va_list *args);
=======
int _printf(const char *format, ...);

#endif
