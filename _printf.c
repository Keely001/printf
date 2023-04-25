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
	char buffer[1024];
	int buffer_size = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				char_printer(args, buffer, &buffer_size);
			else if (*format == 's')
				str_printer(args, buffer, &buffer_size);
			else if (*format == '%')
				percentage_printer(buffer, &buffer_size);
			else if (*format == 'd' || *format == 'i')
				decimal_printer(args, buffer, &buffer_size);
			else if (*format == 'b')
				binary_printer(args, buffer, &buffer_size);
			else if (*format == 'u')
				unsigned_decimal_printer(args, buffer, &buffer_size);
			else if (*format == 'o')
				octal_printer(args, buffer, &buffer_size);
			else if (*format == 'x')
				hexadecimal_printer(args, buffer, &buffer_size, 0);
			else if (*format == 'X')
				hexadecimal_printer(args, buffer, &buffer_size, 1);
			else
			{
				buffer[buffer_size++] = '%';
				buffer[buffer_size++] = *format;
				i += 2;
			}
		}
		else
		{
			buffer[buffer_size++] = *format;
			i++;
		}
		format++;
	}

	va_end(args);

	print_buffer(buffer, buffer_size);

	return (i);
}
