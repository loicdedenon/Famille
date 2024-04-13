/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "../includes/my.h"

int main(int ac, char **av)
{
    if (ac == 0 && av[0][0] == '\0')
        return 84;
    start();
    forward(0.5);
    LidarData *result = malloc(sizeof(LidarData));
    info(result);
    print_lidar_data(result);
    free(result);
    sleep(5);
    return stop();
}
