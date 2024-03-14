/**
 * @file 
 * @author Eric Vantillard
 * @date 13/03/2024
 * @copyright Copyright (c) 2024 Eric Vantillard. All rights reserved.
 */
#include <stdlib.h>

#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>

#include "paint_context.h"
#include "sfml_utils.h"

PaintContext *paint_context_create(sfRenderWindow *window) {
    PaintContext *result = malloc(sizeof(PaintContext));
    result->window = window;
    sfVector2u size = sfRenderWindow_getSize(window);
    result->buffer = sfRenderTexture_create(size.x, size.y,sfFalse);
    sfRenderTexture_clear(result->buffer, sfTransparent);
    result->temp_buffer = sfRenderTexture_create(size.x, size.y,sfFalse);
    sfRenderTexture_clear(result->temp_buffer, sfTransparent);
    result->p0 = (sfVector2i){0, 0};
    result->dragging = sfFalse;
    return result;
}

void paint_context_destroy(PaintContext *self) {
    if (self != NULL) {
        self->window = NULL;
        sfRenderTexture_destroy(self->buffer);
        self->buffer = NULL;
        sfRenderTexture_destroy(self->temp_buffer);
        self->temp_buffer = NULL;
        self->p0 = (sfVector2i){0, 0};
        self->dragging = sfFalse;
        free(self);
    }
}

void paint_context_draw_on_window(PaintContext *self) {
    sfRenderWindow_drawRenderedTexture(self->window, self->buffer);
    sfRenderWindow_drawRenderedTexture(self->window, self->temp_buffer);
}
