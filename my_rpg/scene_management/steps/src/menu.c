/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** menu
*/

#include "scene.h"

void init_menu(workshop_t *workshop)
{
    workshop->menu = malloc(sizeof(menu_t));
    workshop->menu->entity = sfRectangleShape_create();
    sfRectangleShape_getFillColor(workshop->menu->entity);
}

void handle_menu_events(workshop_t *workshop)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(workshop->window, &event)) {
        if (event.type == sfEvtKeyPressed && sfEvtKeyReleased){
            workshop.window(event);
        }
    }
}

/*
 Mettre à jour les variables de menu
*/
void update_menu(workshop_t *workshop)
{
}

void draw_menu(workshop_t *workshop)
{
    sfRenderWindow_clear(workshop->window, sfBlack);
    sfRenderTexture_drawRectangleShape();
    sfRenderWindow_display(sfRectangleShape);
}

/*
 Free tous vos mallocs et sfXXX_create()
*/
void destroy_menu(workshop_t *workshop)
{
}
