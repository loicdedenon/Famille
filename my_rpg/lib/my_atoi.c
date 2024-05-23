/*
** EPITECH PROJECT, 2024
** my_atoi.c
** File description:
** title
*/

int my_atoi(char *str)
{
    int d = 0;

    while (*str < '0' || *str > '9') {
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        d = d * 10 + *str - '0';
        str++;
    }
    return d;
}
