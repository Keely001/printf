#include "main.h"

/**
 * str_printer - function to print strng
 * @args: argument
 * @i: pointer to counter
 *
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
 *
 * Return: none
 */
void percentage_printer(int *i)
{
	_putchar('%');
	*i += 1;
}

/**
 * char_printer - function to print char
 * @args: argument
 * @i: pointer to an integer
 *
 * Return: none
 */

void char_printer(va_list args, int *i)
{
	char a = va_arg(args, int);

	*i += 1;
	_putchar(a);
}

/**
 * decimal_printer - function that prints a decimal integer number
 * @args: arguments
 * @i: pointer to an integer
 *
 * Return: void
 */

void decimal_printer(va_list args, int *i)
{
	int num = va_arg(args, int);
	int div = 1;

	if (num < 0)
	{
	_putchar('-');
	*i += 1;
	num *= -1;
	}
	while (num / div > 9)
		div *= 10;
	while (div != 0)
	{
		_putchar(num / div + '0');
		*i += 1;
		num %= div;
		div /= 10;
	}
}

/**
 * binary_printer - function that prints binary representation of numbers.
 * @args: argument
 * @i: pointer to the counter
 * Return: none
 */
void binary_printer(va_list args, int *i)
{
	unsigned int number = va_arg(args, unsigned int);
	int binary[32];
	int j = 0;

	if (number == 0)
	{
		_putchar('0');
		*i += 1;
		return;
	}

	while (number > 0)
	{
		binary[j] = number % 2;
		number /= 2;
		j++;
	}

	for (j--; j >= 0; j--)
	{
		_putchar(binary[j] + '0');
		*i += 1;
	}
}
