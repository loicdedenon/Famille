/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** my strcat
*/

char *my_strcat(char *dest, char const *src)
{
    char *l = dest;

    while (*l != '\0') {
        l++;
    }
    while (*src != '\0') {
        *l = *src;
        l++;
        src++;
    }
    *l = '\0';
    return dest;
}
