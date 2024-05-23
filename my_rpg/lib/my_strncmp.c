/*
** EPITECH PROJECT, 2023
** my_strncpm.c
** File description:
** my strcpm
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return 1;
        if (s1[i] == '\0')
            return 0;
    }
    return 0;
}
