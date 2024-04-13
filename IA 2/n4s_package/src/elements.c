/*
** EPITECH PROJECT, 2024
** elements
** File description:
** elements
*/

#include "../includes/my.h"

int start(void)
{
    return send_command("START_SIMULATION\n", NULL);
}

int stop(void)
{
    return send_command("STOP_SIMULATION\n", NULL);
}

int info(LidarData *result)
{
    ResponseHeader *rh = malloc(sizeof(ResponseHeader));
    int err = send_command("GET_INFO_LIDAR\n", rh);
    //TODO Free char * in Response Header
    if (err == 0) {
        err = parse_lidar_data(rh->data,result);
    }
    free(rh);
    return err;
}
