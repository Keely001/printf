#include "main.h"

/**
 * _printf - produces output according to format
 * @format: charachter string to be printed
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;

	while (*format)
	{
		if (*format == 'c')
		{
			const char b = va_arg(args, int);

			_putchar(b);
			i++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char*);

			if (str == NULL)
			{
				str = "(null)";
			}
			while (*str)
			{
				_putchar(*str);
				str++;
				i++;
			}
		}
		else
		{
			if (*format == '%')
			{
				_putchar('%');
				i++;
			}
		}
		format++;
	}
	va_end(args);
	return (i);
}
