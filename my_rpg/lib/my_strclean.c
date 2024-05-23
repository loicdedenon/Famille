/*
** EPITECH PROJECT, 2024
** my_strclean.c
** File description:
** cleans a string
*/

#include "../include/my.h"

int my_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
    return 1;
    if (c == '\v' || c == '\f' || c == '\r')
    return 1;
    return 0;
}

void clean(char *str_dirty, char *str_clean, int n)
{
    int j = 0;
    int i = 0;

    while (my_isspace(str_dirty[i]) && i < n)
        i++;
    while (i < n) {
        if (!my_isspace(str_dirty[i]) ||
        (i + 1 < n && !my_isspace(str_dirty[i + 1]))) {
            str_clean[j] = str_dirty[i];
            j++;
        }
        i++;
    }
    if (j > 0 && my_isspace(str_clean[j - 1]))
        j--;
    str_clean[j] = '\0';
}

char *my_strclean(char *str)
{
    char *str_clean = malloc((my_strlen(str) + 1) * sizeof(char));

    clean(str, str_clean, my_strlen(str));
    return str_clean;
}
