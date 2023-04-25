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
 * print_decimal - function that prints a decimal integer number
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

/**
 * unsigned_decimal_printer - function to print unsigned decimal integer
 * @args: argument
 * @i: pointer to counter
 * Return: none
 */

void unsigned_decimal_printer(va_list args, int *i)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int div = 1;

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
 * octal_printer - function to print octal integer
 * @args: argument
 * @i: pointer to counter
 * Return: none
 */

void octal_printer(va_list args, int *i)
{
	unsigned int num = va_arg(args, unsigned int);
	int octal_num[100];
	int k = 0;

	while (num != 0)
	{
		octal_num[k] = num % 8;
		num /= 8;
		k++;
	}

	k--;

	while (k >= 0)
	{
		_putchar(octal_num[k] + '0');
		*i += 1;
		k--;
	}
}

/**
 * hexadecimal_printer - function to print hexadecimal integer
 * @args: argument
 * @i: pointer to counter
 * @capital: flag to indicate if hex is capital or not
 * Return: none
 */

void hexadecimal_printer(va_list args, int *i, int capital)
{
	unsigned int num = va_arg(args, unsigned int);
	char hex_num[100];
	int n = 0;

	while (num != 0)
	{
		int temp = 0;
		temp = num % 16;

		if (temp < 10)
			hex_num[n] = temp + 48;
		else
			hex_num[n] = temp + (capital ? 55 : 87);

		num /= 16;
		n++;
	}

	n--;

	while (n >= 0)
	{
		_putchar(hex_num[n]);
		*i += 1;
		n--;
	}
}

/**
 * my_write - writes a string to the standard output
 *
 * @str: the string to be written
 *
 * This function uses a local buffer of 1024 chars in order to minimize the number
 * of calls to the `write()` function. It iterates over the characters in `str`
 * and adds them to the buffer one by one. Whenever the buffer becomes full, the
 * function writes the contents of the buffer to the standard output and resets
 * the length of the buffer to 0. Finally, after processing all the characters
 * in `str`, the function writes any remaining characters in the buffer to the
 * standard output.
 *
 * Return: void
 */

void my_write(const char *str)
{
    char buffer[1024];
    size_t len = 0;

    while (*str != '\0')
    {
        buffer[len++] = *str++;
        if (len == 1024)
        {
            write(STDOUT_FILENO, buffer, len);
            len = 0;
        }
    }

    if (len > 0)
    {
        write(STDOUT_FILENO, buffer, len);
    }
}
