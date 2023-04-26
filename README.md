# **\_printf - Custom Implementation of printf**

\_printf is a custom implementation of the standard C library function
printf. It allows for formatted output to stdout, the standard output
stream. The function takes a format string and a variable number of
arguments, similar to the original printf function, and returns the
number of characters printed (excluding the null byte used to end output
to strings).

## **Prototype**

int \_printf(const char \*format, \...);

## **Return Value**

The \_printf function returns the number of characters printed on
success, and -1 on failure.

## **Format Specifiers**

\_printf supports the following format specifiers:

-   %c: Prints a single character.

-   %s: Prints a string.

-   %%: Prints a literal \'%\' character.

-   %d, %i: Prints a signed integer in decimal format.

## **Usage**

The \_printf function is used similar to the original printf function.
It takes a format string as its first argument, which can contain format
specifiers followed by optional arguments. The format specifiers are
replaced by the corresponding values of the arguments, and the resulting
string is printed to stdout.

Example:

#include \"main.h\" int main(void) { char c = \'H\'; char \*s =
\"Hello\"; int num = 123; \_printf(\"Character: %c\\n\", c);
\_printf(\"String: %s\\n\", s); \_printf(\"Literal Percentage: %%\\n\");
\_printf(\"Decimal Number: %d\\n\", num); return 0; }

Output:

Character: H String: Hello Literal Percentage: % Decimal Number: 123

## **Notes**

-   \_printf currently does not support all the advanced features and
    > format specifiers of the original printf function. It only
    > supports %c, %s, %%, %d, and %i format specifiers as mentioned
    > above.

-   \_printf does not handle precision or field width specifiers. It
    > only supports basic printing of characters, strings, and signed
    > integers in decimal format.

-   \_printf does not support argument promotion or type casting. The
    > correct data types should be passed as arguments according to the
    > format specifiers in the format string.

## **Dependencies**

\_printf function uses a custom header file main.h which contains
function prototypes and necessary macros.

## **Compilation**

\_printf can be compiled using a C compiler with the following command:

gcc -Wall -Werror -Wextra -pedantic \*.c -o printf

## **Author**

This \_printf implementation is written by Jimmy Mutuku and Jewhalo Ali
as a part of a class project.