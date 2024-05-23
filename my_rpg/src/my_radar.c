/*
** EPITECH PROJECT, 2023
** window
** File description:
** archi au secours
*/

#include "../include/my.h"


void repair(sfRenderWindow* window, sfEvent event)
{
    

    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

Position_t player(sfEvent event, sfVector2i *pos)
 {
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        pos->x = event.key.code += 5;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        pos->x = event.key.code -= 5;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
        pos->x = event.key.code += 5;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
        pos->x = event.key.code -= 5;
    }
 }


int main(void)
{
    sfEvent event;
    sfRenderWindow *window;
    sfTexture *texture = sfTexture_createFromFile
        ("./sprites/maison1.png", NULL);
    sfTexture *avion2 = sfTexture_createFromFile
        ("./sprites/donald2.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite *avion = sfSprite_create();
    sfVideoMode video_mode = {1920, 1080, 32};
    sfVector2f scale = {1, 1};
    sfVector2i *pos;

    window = sfRenderWindow_create(video_mode,
    "#myradar", sfDefaultStyle, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(avion, avion2, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setScale(avion, scale);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, avion, NULL);
        player(event,pos);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event))
            repair(window, event);
    }
    sfRenderWindow_destroy(window);
}
