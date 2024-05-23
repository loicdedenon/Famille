/*
** EPITECH PROJECT, 2023
** my_unsigned_decimal.c
** File description:
** my unsigned decimal
*/

#include <stdarg.h>
#include "../include/my.h"

int my_put_unsigned_decimal(unsigned int nb)
{
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    } else {
        my_putchar(nb + '0');
    }
    return 0;
}

void flag_unsigned(va_list list)
{
    my_put_unsigned_decimal(va_arg(list, unsigned int));
}
