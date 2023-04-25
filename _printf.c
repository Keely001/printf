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
	char buffer[1024];
	int i = 0, k = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			buffer[k++] = format[i++];
			if (k == 1024)
			{
				print_buffer(buffer, k);
				k = 0;
			}
			continue;
		}
		i++;
		if (format[i] == '\0')
			return (-1);
		switch (format[i])
		{
			case 'c':
				k += char_printer(args, &buffer[k]);
				break;
			case 's':
				k += str_printer(args, &buffer[k]);
				break;
			case '%':
				buffer[k++] = '%';
				break;
			case 'd':
			case 'i':
				k += decimal_printer(args, &buffer[k]);
				break;
			case 'b':
				k += binary_printer(args, &buffer[k]);
				break;
			case 'u':
				k += unsigned_decimal_printer(args, &buffer[k]);
				break;
			case 'o':
				k += octal_printer(args, &buffer[k]);
				break;
			case 'x':
				k += hexadecimal_printer(args, &buffer[k], 0);
				break;
			case 'X':
				k += hexadecimal_printer(args, &buffer[k], 1);
				break;
			default:
				buffer[k++] = '%';
				buffer[k++] = format[i];
				break;
		}
		i++;
		if (k == 1024)
		{
			print_buffer(buffer, k);
			k = 0;
		}
	}
	if (k > 0)
		print_buffer(buffer, k);
	va_end(args);
	return (k);
}
