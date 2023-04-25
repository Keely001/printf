#include "main.h"

/**
 * str_printer - function to print strng
 * @args: argument
 * @count: pointer to counter
 * @buff_size: position of buffer
 * @buffer: array of characters
 * Return: none
 */
void str_printer(va_list args, int *buff_size, char buffer[], int *count)
{
        char* str = va_arg(args, char*);
        int len = strlen(str);

        for (int i = 0; i < len; i++)
        {
                buffer[(*buff_size)++] = str[i];
		*count++;
                if (*buff_size == 1024)
                {
                print_buffer(buffer, *buff_size);
                *buff_size = 0;
                }
        }
}

/**
 * percentage_printer - function to print char
 * @count: pointer to counter
 * @buff_size: position of buffer
 * @buffer: array of characters
 * Return: none
 */
void percentage_printer(int *buff_size, char buffer[], int *count)
{
        buffer[(*buff_size)++] = '%';
	*count++;
}


/**
 * char_printer - function to print char
 * @args: argument
 * @count: pointer to counter
 * @buff_size: position of buffer
 * @buffer: array of characters
 * Return: none
 */

void char_printer(va_list args, int *buff_size, char buffer[], int *count)
{
        char c = va_arg(args, int);
        buffer[(*buff_size)++] = c;
	*count++;
}

/**
 * print_decimal - function that prints a decimal integer number
 * @args: argument
 * @count: pointer to counter
 * @buff_size: position of buffer
 * @buffer: array of characters
 * Return: void
 */


void decimal_printer(va_list args, int *buff_size, char buffer[], int *count)
{
        int num = va_arg(args, int);
        char str_num[20];
        int i = 0;

        if (num < 0)
        {
                buffer[(*buff_size)++] = '-';
		*count++;
                num = -num;
        }if (num == 0)
        {
                str_num[i++] = '0';
        }
        else
        {
                while (num != 0)
                {
                        int digit = num % 10;
                        str_num[i++] = digit + '0';
                        num /= 10;
                }
        }
        for (int j = i - 1; j >= 0; j--)
        {
                buffer[(*buff_size)++] = str_num[j];
		*count++;
                if (*buff_size == 1024)
                {
                        print_buffer(buffer, *buff_size);
                        *buff_size = 0;
                }
        }
}

/**
 * binary_printer - function that prints binary representation of numbers.
 * @args: argument
 * @count: pointer to counter
 * @buff_size: position of buffer
 * @buffer: array of characters
 * Return: none
*/
void binary_printer(va_list args, int *buff_size, char buffer[], int *count)
{
    unsigned int num = va_arg(args, unsigned int);
    char str_num[32];
    int i = 0;

    do {
        str_num[i++] = (num % 2) + '0';
        num /= 2;
    } while (num != 0);
    while (i < 8) {
        str_num[i++] = '0';
    }

    for (int j = i - 1; j >= 0; j--)
    {
        buffer[(*buff_size)++] = str_num[j];
	*count++;

        if (*buff_size == 1024)
        {
            print_buffer(buffer, *buff_size);
            *buff_size = 0;
        }
    }
}

/**
 * unsigned_decimal_printer - function to print unsigned decimal integer
 * @args: argument
 * @count: pointer to counter
 * @buff_size: position of buffer
 * @buffer: array of characters
 * Return: none
 */

void unsigned_decimal_printer(va_list args, int *buff_size, char buffer[], int *count)
{
    unsigned int num = va_arg(args, unsigned int);
    char str_num[32];
    int i = 0;
    do {
        str_num[i++] = (num % 10) + '0';
        num /= 10;
    }
   while (num != 0);

    for (int j = i - 1; j >= 0; j--)
    {
        buffer[(*buff_size)++] = str_num[j];
	*count++;

        if (*buff_size == 1024)
        {
            print_buffer(buffer, *buff_size);
            *buff_size = 0;
        }
    }
}


/**
 * octal_printer - function to print octal integer
 * @args: argument
 * @count: pointer to counter
 * @buff_size: position of buffer
 * @buffer: array of characters
 * Return: none
 */

void octal_printer(va_list args, int *buff_size, char buffer[], int *count)
{
    unsigned int num = va_arg(args, unsigned int);
    char str_num[32];
    int i = 0;

    do {
        str_num[i++] = (num % 8) + '0';
        num /= 8;
    } while (num != 0);

    for (int j = i - 1; j >= 0; j--)
    {
        buffer[(*buff_size)++] = str_num[j];
	*count++;

        if (*buff_size == 1024)
        {
            print_buffer(buffer, *buff_size);
            *buff_size = 0;
        }
    }
}

/**
 * hexadecimal_printer - function to print hexadecimal integer
 * @args: argument
 * @count: pointer to counter
 * @buff_size: position of buffer
 * @buffer: array of characters
 * @uppercase: dif
 * Return: none
 */

void hexadecimal_printer(va_list args, int *buff_size, char buffer[], int uppercase, int *count)
{
    unsigned int num = va_arg(args, unsigned int);
    char str_num[32];
    int i = 0;

    do {
        int digit = num % 16;
        if (digit < 10)
            str_num[i++] = digit + '0';
        else
            str_num[i++] = digit - 10 + 'a';
        num /= 16;
    } while (num != 0);

    for (int j = i - 1; j >= 0; j--)
    {
        buffer[(*buff_size)++] = str_num[j];
	*count++;

        if (*buff_size == 1024)
        {
            print_buffer(buffer, *buff_size);
            *buff_size = 0;
        }
    }
}

