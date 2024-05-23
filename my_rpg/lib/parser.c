/*
** EPITECH PROJECT, 2024
** minishell_parser.c
** File description:
** title
*/

#include "../include/my.h"
#include "../include/struct.h"

int delimitor(char c, char d)
{
    if (c == d || c == '\t')
        return 0;
    else
        return 1;
}

int counter(char const *str, char d)
{
    int count = 0;
    int in = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (delimitor(str[i], d)) {
            in = 1;
        }
        if (!delimitor(str[i], d) && in) {
            count++;
            in = 0;
        }
    }
    return count;
}

char *copy(char const *str, int start, int end)
{
    int len = end - start;
    char *word = malloc((len + 1) * sizeof(char));

    my_strncpy(word, &str[start], len);
    word[len] = '\0';
    return word;
}

char **allocation(char const *str, int count, char d)
{
    char **args = malloc((count + 2) * sizeof(char *));
    int start = 0;
    int i = 0;

    count = 0;
    while (str[i] != '\0') {
        if (!delimitor(str[i], d) && i > start) {
            args[count] = copy(str, start, i);
            count++;
            start = i + 1;
        }
        i++;
    }
    if (i > start) {
        args[count] = copy(str, start, i);
        count++;
    }
    args[count] = NULL;
    return args;
}

char **parser(char const *str, char d)
{
    int count = counter(str, d);
    char **result = allocation(str, count, d);

    return result;
}
