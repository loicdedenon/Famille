/*
** EPITECH PROJECT, 2024
** my_isnum.c
** File description:
** title
*/

int num_addon(int c)
{
    if ((c >= '1' && c <= '9'))
        return 0;
    else
        return 1;
}

int my_isnum(int c)
{
    if (num_addon(c) == 1)
        return 1;
    else
        return 0;
}
