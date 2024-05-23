/*
** EPITECH PROJECT, 2024
** my_isalnum.c
** File description:
** title
*/

#include "../include/my.h"

int minishell_only(char c)
{
    if (c == '/' || c == '-' || c == '.')
        return 0;
    else
        return 1;
}

int alnum_addon(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 0;
    else if (c >= '0' && c <= '9')
        return 0;
    else
        return 1;
}

int my_isalnum(char c)
{
    if (minishell_only(c) == 0)
        return 1;
    else if (alnum_addon(c) == 0)
        return 1;
    else
        return 0;
}
