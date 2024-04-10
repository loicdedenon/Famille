/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int ac, char **av)
{
    setbuf(stdout, NULL);
    start_simulation();
    car_forward(0.5);
    get_info_lidar();
    sleep(20);
    return stop_simulation();
}
