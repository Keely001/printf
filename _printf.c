#include "main.h"

/**
 * printf - produces output according to format
 * @format: pointer to a string
 *
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
			{
				char a = va_arg(args, int);
				i += 1;
				_putchar(a);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				if (str == NULL)
					str = "(null)";
				while (*str != '\0')
				{
					i += 1;
					_putchar(*str);
					str++;
				}
			}
			else if (*format == '%')
			{
				i += 1;
				_putchar('%');
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				i += 2;
			}
		}
		else
		{
			i += 1;
			_putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (i);
}

