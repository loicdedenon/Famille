/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** my printf
*/

#include <stdarg.h>
#include "../include/my.h"

int handling(const char format, va_list list)
{
    switch (format) {
        case 'o':
            my_put_octal(va_arg(list, int));
            return 1;
        case 'u':
            my_put_unsigned_decimal(va_arg(list, int));
            return 1;
        case 'x':
            my_hexadecimaldown(va_arg(list, int));
            return 1;
        case 'X':
            my_hexadecimalup(va_arg(list, int));
            return 1;
        case 'b':
            binary(va_arg(list, int));
            return 1;
        default:
            return 0;
    }
}

int flagz2(const char *format, int a, va_list list)
{
    if (handling(format[a], list) == 0) {
        return a + 1;
    }
    return a;
}

int flagz(const char *format, int a, va_list list)
{
    switch (format[a]) {
        case 's':
            my_putstr(va_arg(list, char *));
            return 0;
        case 'i':
        case 'd':
            my_put_nbr(va_arg(list, int));
            return 0;
        case 'c':
            my_putchar(va_arg(list, int));
            return 0;
        case '%':
            my_putchar('%');
            return 0;
        default:
            a = flagz2(format, a, list);
            return 0;
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int a = 0;

    va_start(list, format);
    while (format[a] != '\0') {
        if (format[a] == '%') {
            a = a + 1;
            flagz(format, a, list);
        } else {
            my_putchar(format[a]);
        }
        a = a + 1;
    }
    va_end(list);
    return (0);
}
