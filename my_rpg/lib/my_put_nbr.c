/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** my put nbr
*/

#include "../include/my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    } else {
        my_putchar(nb + '0');
    }
}
