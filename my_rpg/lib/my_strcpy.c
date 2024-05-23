/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** my strcpy
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    char u;

    while (i < my_strlen(src)) {
        u = src[i];
        dest[i] = u;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
