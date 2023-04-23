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
	char a, *str;

	va_start(args, format);

	while ((a = *format) != '\0')
	{
		if (a != '%')
		{
			_putchar(a);
			i++;
		}
		else
		{
			switch (*format++)
			{
				case 'c':
				_putchar(va_arg(args, int));
				i++;
				break;

				case '%':
				_putchar('%');
				i++;
				break;

				case 's':
				str = va_arg(args, char *);
				if (str == NULL)
				{
					str = "(NULL)";
				}
				while (*str != '\0')
				{
					_putchar(*str);
					i++;
					str++;
				}
				break;

				default:
				_putchar('%');
				_putchar(a);
				i += 2;
				break;
			}
		}
		format++;
	}
	va_end(args);
	return (i);
}
