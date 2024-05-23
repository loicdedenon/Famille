/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** settings
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

typedef struct workshop_s workshop_t;

void init_settings(workshop_t *workshop);
void handle_settings_events(workshop_t *workshop);
void update_settings(workshop_t *workshop);
void draw_settings(workshop_t *workshop);
void destroy_settings(workshop_t *workshop);

#endif // !SETTINGS_H_
