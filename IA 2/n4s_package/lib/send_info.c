/*
** EPITECH PROJECT, 2024
** send_info
** File description:
** aaa
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int send_info(char *command)
{
    int nbr_read = 0;
    size_t buf_size = 1024;
    char *buffer = 0;

    fprintf(stderr, "send command %s\n", command);
    write(1, command, strlen(command));
    buffer = malloc(sizeof(char)*buf_size);
    nbr_read = getline(&buffer, &buf_size, stdin);
    if (nbr_read > 0){
        fprintf(stderr, "receive response %s\n", buffer);
        free(buffer);
        return 0;
    } else {
        free(buffer);
        return -1;
    }
}
