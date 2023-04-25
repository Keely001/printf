#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c);

int _printf(const char *format, ...);

void char_printer(va_list args, int *i);

void str_printer(va_list args, int *i);

void percentage_printer(int *i);

void decimal_printer(va_list args, int *i);

void binary_printer(va_list args, int *i);

void unsigned_decimal_printer(va_list args, int *i);

void octal_printer(va_list args, int *i);

void hexadecimal_printer(va_list args, int *i, int uppercase);

void my_write(const char *str);

#endif
