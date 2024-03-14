/*
** EPITECH PROJECT, 2024
** my_paint.c
** File description:
** paint
*/

#include <stdlib.h>

#include <SFML/Graphics.h>

#include "paint_context.h"
#include "paint_state.h"

void repair(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void fenetre()
{
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("Votre texte de paragraphe.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVideoMode video_mode = {1920, 1080, 32};
    sfVector2f scale = {1, 1};

    sfRenderWindow *window = sfRenderWindow_create(video_mode,"#myradar", sfDefaultStyle, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);

    PaintState paint_state = PAINT_STATE_IDLE;
    PaintContext *paint_context =  paint_context_create(window);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, sprite, NULL);
        paint_context_draw_on_window(paint_context);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            repair(window, event);
            paint_state = paint_state_handle_event(paint_state, paint_context, event);
        }
    }

    paint_context_destroy(paint_context);
    sfRenderWindow_destroy(window);
}
