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

static sfSprite *load_background() {
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("Votre texte de paragraphe.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfVector2f scale = {1, 1};
    sfSprite_setScale(sprite, scale);
    return sprite;
}

void fenetre()
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode,"#myradar", sfDefaultStyle, NULL);

    PaintState paint_state = PAINT_STATE_IDLE;
    PaintContext *paint_context =  paint_context_create(window);
    sfSprite* background = load_background();

    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, background, NULL);
        paint_context_draw_on_window(paint_context);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            repair(window, event);
            paint_state = paint_state_handle_event(paint_state, paint_context, event);
        }
    }

    sfSprite_destroy(background);
    paint_context_destroy(paint_context);
    sfRenderWindow_destroy(window);
}
