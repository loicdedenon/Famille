/*
** EPITECH PROJECT, 2024
** my_rpg
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
} SCENE_END;

typedef struct scene_s {
    void (*init)(workshop_t *game);
    void (*handle_events)(workshop_t *game);
    void (*update)(workshop_t *game);
    void (*draw)(workshop_t *game);
    void (*destroy)(workshop_t *game);
} scene_t;

/*
 Ici vous pourrez ajouter tous les éléments
 indépendant de votre scène (ex: Player, map, des sons, des boutons, etc.)
*/
typedef struct menu_s {
    sfRectangleShape *entity;

} menu_t;

/*
 Ici vous pourrez ajouter tous les éléments
 indépendant de votre scène (ex: Player, map, des sons, des boutons, etc.)
*/
typedef struct settings_s {
    sfRectangleShape *entity;

} settings_t;

/*
 Ici vous pourrez ajouter tous les éléments
 indépendant de votre scène (ex: Player, map, des sons, des boutons, etc.)
*/
typedef struct game_s {
    sfRectangleShape *entity;
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
