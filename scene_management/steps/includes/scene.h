/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-mypaint-loic.dedenon
** File description:
** scene
*/


#ifndef STRUCT_H_
    #define STRUCT_H_
        #include <SFML/Graphics.h>
        #include <stdlib.h>
        #include "menu.h"
        #include "settings.h"
    #include "game.h"

    #define NB_SCENES 3

typedef struct workshop_s workshop_t;

typedef enum SCENE {
    MENU,
    SETTINGS,
    GAME
} SCENE_E;

typedef struct scene_s
{
    void (*init)(workshop_t *game);
    void (*handle_events)(workshop_t *game);
    void (*update)(workshop_t *game);
    void (*draw)(workshop_t *game);
    void (*destroy)(workshop_t *game);
} scene_t;

typedef struct menu_s {
    sfRectangleShape *entity;
    /*
        Ici vous pourrez ajouter tous les éléments
        indépendant de votre scène (ex: Player, map, des sons, des boutons, etc.)
    */
} menu_t;

typedef struct settings_s {
    sfRectangleShape *entity;
    /*
        Ici vous pourrez ajouter tous les éléments
        indépendant de votre scène (ex: Player, map, des sons, des boutons, etc.)
    */
} settings_t;

typedef struct game_s {
    sfRectangleShape *entity;
    /*
        Ici vous pourrez ajouter tous les éléments
        indépendant de votre scène (ex: Player, map, des sons, des boutons, etc.)
    */
} game_t;

typedef struct workshop_s {
    SCENE_E current_scene;
    sfRenderWindow *window;
    menu_t *menu;
    settings_t *settings;
    game_t *game;
    scene_t scenes[NB_SCENES];
} workshop_t;

#endif // !STRUCT_H_
