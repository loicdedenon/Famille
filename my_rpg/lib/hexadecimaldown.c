/*
** EPITECH PROJECT, 2023
** hexadecimaldown.c
** File description:
** hexa decimal
*/

#include "../include/my.h"

void my_hexadecimaldown(unsigned int nb)
{
    if (nb >= 16) {
        my_hexadecimaldown(nb / 16);
        my_hexadecimaldown(nb % 16);
    } else {
        if (nb <= 9)
            my_putchar(nb + '0');
        else
            my_putchar(nb - 10 + 'a');
    }
}
