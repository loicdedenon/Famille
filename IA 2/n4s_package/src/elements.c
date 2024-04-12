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

int info(void)
{
    return send_command("GET_INFO_LIDAR\n", NULL);
}
