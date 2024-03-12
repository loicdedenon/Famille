/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-mypaint-loic.dedenon
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
