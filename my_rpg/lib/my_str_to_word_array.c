/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** title
*/

#include "../include/my.h"
#include "../include/struct.h"

int words_count(char const *str)
{
    int count = 0;
    int in = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalnum(str[i])) {
            in = 1;
        }
        if (!my_isalnum(str[i]) && in) {
            count++;
            in = 0;
        }
    }
    return count;
}

char *copy_word(char const *str, int start, int end)
{
    int len = end - start;
    char *word = malloc((len + 1) * sizeof(char));

    my_strncpy(word, &str[start], len);
    word[len] = '\0';
    return word;
}

char **initialisor(char const *str, int count)
{
    char **args = malloc((count + 2) * sizeof(char *));
    int start = 0;
    int i = 0;

    if (str[0] == '\0') {
        args[0] = NULL;
        return args;
    }
    count = 0;
    while (str[i] != '\0') {
        if (!my_isalnum(str[i]) && i > start) {
            args[count] = copy_word(str, start, i);
            count++;
            start = i + 1;
        }
        i++;
    }
    return args;
}

char **mem_alloc(char const *str, int count)
{
    char **args = initialisor(str, count);
    int i = strlen(str);
    int start = i - strlen(args[count - 1]);

    if (i > start) {
        args[count] = copy_word(str, start, i);
        count++;
    }
    args[count] = NULL;
    return args;
}

char **my_str_to_word_array(char const *str)
{
    int count = words_count(str);
    char **result = mem_alloc(str, count);

    return result;
}
