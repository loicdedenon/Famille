/*
** EPITECH PROJECT, 2024
** str_to_word_array
** File description:
** e
*/

#include "../includes/my.h"

void free_arr(char **array)
{
    void *add = array;

    for (; *array; array++)
        free(*array);
    free(add);
}

static int my_str_len_spe(char *str, char sup)
{
    int i = 0;

    for (; *str != sup; str++)
        i++;
    return i;
}

static int count_word(char *str, char sup)
{
    int count = 0;
    int in = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != sup && !in) {
            count++;
            in = 1;
        }
        if (str[i] == sup)
            in = 0;
    }
    return count;
}

static void fill_str_mem(char **array, char *str, int len_spe, int curr_wrd)
{
    int ind;

    for (ind = 0; ind != len_spe; ind++)
        array[curr_wrd][ind] = str[ind];
    array[curr_wrd][ind] = '\0';
}

char **my_str_to_word_array(char const *str, char sup)
{
    char **array = malloc(sizeof(char *) * (count_word(str, sup) + 1));
    int i = 0;
    int current_word = 0;
    int len_spe = 0;

    for (int j = 0; str[j] && str[i]; j++) {
        len_spe = my_str_len_spe(&str[i], sup);
        if (str[i] != sup && len_spe != 0) {
            array[current_word] = malloc(sizeof(char) * (len_spe + 1));
            fill_str_mem(array, &str[j], len_spe, current_word);
            current_word++;
            i += (len_spe);
            j += len_spe;
        }
        i++;
    }
    array[current_word] = NULL;
    return array;
}
