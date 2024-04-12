/*
** EPITECH PROJECT, 2024
** split
** File description:
** split
*/

#include "../includes/my.h"

char **split(char *raw_cmd, char *limit)
{
    char *ptr = NULL;
    char **cmd = NULL;
    size_t idx = 0;

    cmd = (char **)malloc((100 + 1) * sizeof(char *));
    for (idx = 0; idx < 100; ++idx) {
        ptr = strtok((idx == 0) ? raw_cmd : NULL, limit);
        if (ptr == NULL)
            break;
        cmd[idx] = strdup(ptr);
        if_split(cmd, idx);
    }
    cmd[idx] = NULL;
    return cmd;
}

int if_split(char **cmd, size_t idx)
{
    if (cmd[idx] == NULL) {
        for (size_t i = 0; i < idx; ++i)
            free(cmd[i]);
        free(cmd);
        return 84;
    }
    return 0;
}
