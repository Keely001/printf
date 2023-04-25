#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int _putchar(char c);

int _printf(const char *format, ...);

void char_printer(va_list args, int *buff_size, char buffer[], int *count);

void str_printer(va_list args, int *buff_size, char buffer[], int *count);

void percentage_printer(int *buff_size, char buffer[], int *count);

void decimal_printer(va_list args, int *buff_size, char buffer[], int *count);

void binary_printer(va_list args, int *buff_size, char buffer[], int *count);

void unsigned_decimal_printer(va_list args, int *buff_size, char buffer[], int *count);

void octal_printer(va_list args, int *buff_size, char buffer[], int *count);

void hexadecimal_printer(va_list args, int *buff_size, char buffer[], int uppercase, int *count);

void print_buffer(char *buffer, int size);

#endif
