/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-mypaint-loic.dedenon
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

typedef struct workshop_s workshop_t;

void init_game(workshop_t *workshop);
void handle_game_events(workshop_t *workshop);
void update_game(workshop_t *workshop);
void draw_game(workshop_t *workshop);
void destroy_game(workshop_t *workshop);

#endif // !GAME_H_
