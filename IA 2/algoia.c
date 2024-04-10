/*
** EPITECH PROJECT, 2024
** n4s
** File description:
** n4s
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

float min(float f1, float f2)
{
    if (f1 < f2) {
        return f1;
    } else {
        return f2;
    }
}

float max(float f1, float f2)
{
    if (f1 > f2) {
        return f1;
    } else {
        return f2;
    }
}

float in_range(float value, float lower, float upper)
{
    return min(upper, max(lower, value));
}

/// @brief
/// @param engine_power percentage of engine power between 0.5 and 1 inclusive
/// @return
int car_forward(float engine_power)
{
    char buffer[1024];

    sprintf(buffer, "CAR_FORWARD:%.2f\n", in_range(engine_power, 0.5, 1));
    return send_command(buffer);
}

int send_command(char *command)
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
