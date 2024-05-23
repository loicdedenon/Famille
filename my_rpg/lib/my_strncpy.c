/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** my strncpy
*/

#include "../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int u;
    int len = my_strlen(src);

    while (i < n && src[i] != '\0') {
        u = src[i];
        dest[i] = u;
        i++;
    }
    if (n > len) {
        dest[i] = '\0';
    }
    return (dest);
}
