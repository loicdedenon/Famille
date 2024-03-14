/**
 * @file 
 * @author Eric Vantillard
 * @date 13/03/2024
 * @copyright Copyright (c) 2024 Eric Vantillard. All rights reserved.
 */

#include "paint_context.h"

#include <stdlib.h>

#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>

#include "SFML/Graphics/Sprite.h"

PaintContext *paint_context_create(sfRenderWindow *window) {
    PaintContext *result = malloc(sizeof(PaintContext));
    result->window = window;
    sfVector2u size = sfRenderWindow_getSize(window);
    result->buffer = sfRenderTexture_create(size.x, size.y,sfFalse);
    sfRenderTexture_clear(result->buffer, sfTransparent);
    result->p0 = (sfVector2i){0, 0};
    return result;
}

void paint_context_destroy(PaintContext *self) {
    if (self != NULL) {
        self->window = NULL;
        sfRenderTexture_destroy(self->buffer);
        self->buffer = NULL;
        self->p0 = (sfVector2i){0, 0};
        free(self);
    }
}

void paint_context_draw_rect(PaintContext *self, sfRectangleShape *shape) {
    sfRenderTexture_drawRectangleShape(self->buffer, shape,NULL);
}

void paint_context_draw_on_window(PaintContext *self) {
    sfRenderTexture_display(self->buffer);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, sfRenderTexture_getTexture(self->buffer),sfTrue);
    sfRenderWindow_drawSprite(self->window, sprite,NULL);
    sfSprite_destroy(sprite);
}
