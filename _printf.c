#include "main.h"


void char_printer(va_list args, int *i);
void str_printer(va_list args, int *i);
void percentage_printer(int *i);

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

/**
 * char_printer - function to print char
 * @args: argument
 * @i: pointer to counter
 * Return: none
 */

void char_printer(va_list args, int *i)
{
	char a = va_arg(args, int);

	*i += 1;
	_putchar(a);

}

/**
 * str_printer - function to print strng
 * @args: argument
 * @i: pointer to counter
 * Return: none
 */

void str_printer(va_list args, int *i)
{
	char *str = va_arg(args, char*);

	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		_putchar(*str);
		*i += 1;
		str++;
	}
}

/**
 * percentage_printer - function to print char
 * @i: pointer to counter
 * Return: none
 */
void percentage_printer(int *i)
{
	_putchar('%');
	*i += 1;
}

