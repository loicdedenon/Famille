/*
** EPITECH PROJECT, 2023
** my_binary.c
** File description:
** converts_decimals_to_binary
*/

#include "../include/my.h"

void binary(unsigned int nb)
{
    if (nb < 2) {
        switch (nb) {
        case 0:
            my_putchar('0');
            break;
        case 1:
            my_putchar('1');
            break;
        }
    } else {
        binary(nb / 2);
        my_putchar(nb % 2 + '0');
    }
}
