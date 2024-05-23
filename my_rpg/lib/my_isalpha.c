/*
** EPITECH PROJECT, 2024
** my_isalpha.c
** File description:
** title
*/

int alpha_addon(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 0;
    else
        return 1;
}

int my_isalpha(char c)
{
    if (alpha_addon(c) == 1)
        return 1;
    else
        return 0;
}
