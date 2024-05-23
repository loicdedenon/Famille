/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

typedef struct workshop_s workshop_t;

void init_menu(workshop_t *workshop);
void handle_menu_events(workshop_t *workshop);
void update_menu(workshop_t *workshop);
void draw_menu(workshop_t *workshop);
void destroy_menu(workshop_t *workshop);

#endif // !MENU_H_
