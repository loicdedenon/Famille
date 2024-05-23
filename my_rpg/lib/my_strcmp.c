/*
** EPITECH PROJECT, 2023
** my_strcpm.c
** File description:
** my strcpm
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0' && s2[j] != '\0') {
        i++;
        j++;
    }
    if (s1[i] != '\0' || s2[j] != '\0')
        return 1;
    i = 0;
    j = 0;
    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] != s2[j])
        return 1;
        i++;
        j++;
    }
    return 0;
}
