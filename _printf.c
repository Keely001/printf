#include "main.h"


/**
 * _printf - produces output according to format of the input
 * @format: pointer to a string
 *..: variadic arguments.

 * Return: the number of charachters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char buffer[1024];
	int buff_size = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				char_printer(args, &buff_size, buffer, &count);
			else if (*format == 's')
				str_printer(args, &buff_size, buffer, &count);
			else if (*format == '%')
				percentage_printer(&buff_size, buffer, &count);
			else if (*format == 'd' || *format == 'i')
				decimal_printer(args, &buff_size, buffer, &count);
			else if (*format == 'b')
				binary_printer(args, &buff_size, buffer, &count);
			else if (*format == 'u')
				unsigned_decimal_printer(args, &buff_size, buffer, &count);
			else if (*format == 'o')
				octal_printer(args, &buff_size, buffer, &count);
			else if (*format == 'x')
				hexadecimal_printer(args, &buff_size, buffer, 0, &count);
			else if (*format == 'X')
				hexadecimal_printer(args, &buff_size, buffer, 1, &count);
			else
			{
				buffer[buff_size++] = '%';
				buffer[buff_size++] = *format;
				count += 2;
			}
		}
		else
		{
			buffer[buff_size++] = *format;
			count++;
		}
		format++;
		if (buff_size == 1024 || *format == '\0')
		{
			print_buffer(buffer, buff_size);
			buff_size = 0;
		}
	}

	va_end(args);

	return (count);
}
