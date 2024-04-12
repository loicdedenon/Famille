/*
** EPITECH PROJECT, 2024
** forward
** File description:
** forward
*/

#include "../includes/my.h"

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

float in_range(float val, float low, float up)
{
    return min(up, max(low, val));
}

int forward(float horsepower)
{
    char buffer[1024];

    sprintf(buffer, "CAR_FORWARD:%.2f\n", in_range(horsepower, 0, 1));
    ResponseHeader *response = malloc(sizeof(ResponseHeader));
    int err = send_command(buffer,response);
    //TODO free strings in ResponseHeader
    free(response);
    return err;
}
