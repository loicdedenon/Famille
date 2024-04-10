/*
** EPITECH PROJECT, 2024
** action management
** File description:
** aaa
*/

int start_simulation(void)
{
    return send_command("START_SIMULATION\n");
}

int stop_simulation(void)
{
    return send_command("STOP_SIMULATION\n");
}
