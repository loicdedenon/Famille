/*
** EPITECH PROJECT, 2024
** my_paint.c
** File description:
** paint
*/

#include "scene_management/steps/includes/game.h"
#include "scene_management/steps/includes/menu.h"
#include "scene_management/steps/includes/scene.h"
#include "scene_management/steps/includes/settings.h"
#include <stdio.h>

void repair(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

static void if_click(sfRenderWindow* window, sfEvent event)
{
    int i = 0;
    sfVector2i mouse = sfMouse_getPosition(window);

    if (mouse.x >= 816 && mouse.x <= 1062) {
        if (mouse.y >= 526 && mouse.y <= 594)
            i = 1;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        printf("x:,%d y: %d, button: %d\n", event.mouseButton.x, event.mouseButton.y, event.mouseButton.button);
       return (0);
    }
}

typedef enum {
    idle_state,
    drawing_rectangle,
    last_state,
    
}paint_state;

typedef paint_state(*event_handler)(sfRenderWindow*,sfEvent);

paint_state idle_state_handler(sfRenderWindow *window, sfEvent event) {
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR) {
        return (drawing_rectangle);
    }else{
        return (idle_state);
    }
}
paint_state drawing_rectangle_handler(sfRenderWindow *window, sfEvent event) {
    if( event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
    sfTexture *rectangle2 = sfRectangleShape_create();
    sfVector2f scale2 = {1,1};
    sfVector2f position = {event.mouseButton.x, event.mouseButton.y};

        sfRectangleShape_setScale(rectangle2,scale2);
        sfRectangleShape_setPosition(rectangle2,position);
        sfRenderWindow_drawRectangleShape(window,rectangle2,NULL);   
        sfRectangleShape_destroy(rectangle2);
    }
}

int fenetre()
{
    sfEvent event;
    sfRenderWindow *window;
    sfTexture *texture = sfTexture_createFromFile
    ("Votre texte de paragraphe.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVideoMode video_mode = {1920, 1080, 32};
    sfVector2f scale = {1, 1};
    paint_state current_state = idle_state;
    event_handler current_handler = idle_state_handler;

    window = sfRenderWindow_create(video_mode,
    "#myradar", sfDefaultStyle, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            repair(window, event);
            if_click(window, event);
            switch (current_state)
            {
            case idle_state: 
                /* code */
                break;
            case drawing_rectangle:
            //code//
            break;
            default:
                break;
            }
        }
    }
    sfRenderWindow_destroy(window);
}
