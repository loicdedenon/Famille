/*
** EPITECH PROJECT, 2023
** my_str_isalpha.c
** File description:
** my str isalpha
*/

int isalpha_ext(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')
        return 0;
    else
        return 1;
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha_ext(str[i]) == 1)
            return 1;
    }
    return 0;
}
