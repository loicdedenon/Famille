/*
** EPITECH PROJECT, 2024
** B-MUL-200-NCY-2-1-mypaint-loic.dedenon
** File description:
** main
*/

#include "../includes/scene.h"


void init_workshop(workshop_t *workshop)
{
    workshop_t workshop;
    workshop->current_scene = MENU;
    sfVideoMode *rendition = sfVideoMode_getFullscreenModes(sfFullscreen);
    workshop->window = sfWindow_create (*rendition, "workshop", sfDefaultStyle, NULL);
    workshop->scenes[MENU] = (scene_t) {&init_menu, &handle_menu_events, &update_menu, &draw_menu, &destroy_menu};
    workshop->scenes[MENU];
    SCENE_E = NB_SCENES;
}

void destroy_workshop(workshop_t *workshop)
{
    sfWindow_destroy(workshop);
}

int main(void)
{
    return 0;
}
