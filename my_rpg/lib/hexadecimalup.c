/*
** EPITECH PROJECT, 2023
** test4.c
** File description:
** title
*/

#include "../include/my.h"

void my_hexadecimalup(unsigned int nb)
{
    if (nb >= 16) {
        my_hexadecimalup(nb / 16);
        my_hexadecimalup(nb % 16);
    } else {
        if (nb <= 9)
            my_putchar(nb + '0');
        else
            my_putchar(nb - 10 + 'A');
    }
}
