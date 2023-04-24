#include "main.h"


/**
 * _printf - produces output according to format
 * @format: pointer to a string
 *..: variadic arguments.
 * Return: the number of charachters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;

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
				print_decimal(args, &i);
			else
			{
				_putchar('%');
				_putchar(*format);
				i += 2;
			}
		}
		else
			i += _putchar(*format);
		format++;
	}

	va_end(args);

	return (i);
}
