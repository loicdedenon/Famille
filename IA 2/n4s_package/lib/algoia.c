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
    return send_info(buffer);
}

int get_info_lidar(void)
{
    return send_info("GET_INFO_LIDAR\n");
}

/*int wheel_dir(int wheel_direction)
{
     char buffer[1024];

    sprintf(buffer, "CAR_FORWARD:%d\n", in_range(wheel_direction, 1, 1));
    {else {
    sprintf(buffer, "CAR_FORWARD:%d\n", in_range(wheel_direction, -1, 1));    
    }
    return send_info(buffer);
}
*/
