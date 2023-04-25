#include "main.h"

/**
 * _printf - produces output according to format of the input
 * @format: pointer to a string
 *..: variadic arguments.
 * Return: the number of charachters printed
 *
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, k = 0;
	char buffer[1024];

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				char_printer(args, &i);
			else if (*format == 's')
				str_printer(args, &i);
			else if (*format == '%')
				percentage_printer(&i);
			else if (*format == 'd' || *format == 'i')
				decimal_printer(args, &i);
			else if (*format == 'b')
				binary_printer(args, &i);
			else if (*format == 'u')
				unsigned_decimal_printer(args, &i);
			else if (*format == 'o')
				octal_printer(args, &i);
			else if (*format == 'x')
				hexadecimal_printer(args, &i, 0);
			else if (*format == 'X')
				hexadecimal_printer(args, &i, 1);
			else
			{
				_putchar('%');
				_putchar(*format);
				i += 2;
			}
		}
		else
			i += _putchar(*format);
		format;
	}
	va_end(args);

	return (i);
}
