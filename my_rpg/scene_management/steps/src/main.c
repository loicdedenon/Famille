/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** main
*/

#include "../includes/scene.h"



void init_workshop(workshop_t *workshop)
{
    workshop_t workshop;
    sfVideoMode *rendition = sfVideoMode_getFullscreenModes(sfFullscreen);

    workshop->current_scene = MENU;
    workshop->window = sfWindow_create (*rendition, "workshop", sfDefaultStyle
    , NULL);
    workshop->scenes[MENU] = (scene_t)
    {&init_menu, &handle_menu_events, &update_menu, &draw_menu, &destroy_menu};
    workshop->scenes[MENU];
    SCENE_END = NB_SCENES;
}

void destroy_workshop(workshop_t *workshop)
{
    sfWindow_destroy(workshop);
}

int main(void)
{
    return 0;
}
