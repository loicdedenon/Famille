/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** title
*/

#include "../include/my.h"

char *my_strdup(const char *str)
{
    char *dup = malloc(my_strlen(str) + 1);

    my_strcpy(dup, str);
    return dup;
}
