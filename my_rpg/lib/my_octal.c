/*
** EPITECH PROJECT, 2023
** my_octal.c
** File description:
** my octal
*/

#include <stdarg.h>
#include "../include/my.h"

void my_put_octal(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 7) {
        my_put_nbr(nb / 8);
        my_putchar((nb % 8) + '0');
    } else {
        my_putchar(nb + '0');
    }
}

int flag_octal(va_list list)
{
    my_put_octal(va_arg(list, int));
    return (0);
}
