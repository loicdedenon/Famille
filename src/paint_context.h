/**
 * @file 
 * @author Eric Vantillard
 * @date 13/03/2024
 * @copyright Copyright (c) 2024 Eric Vantillard. All rights reserved.
 */

#ifndef PAINT_CONTEXT_H
#define PAINT_CONTEXT_H

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

typedef struct PaintContext {
 sfRenderWindow* window;
 sfRenderTexture* buffer;
 sfVector2i p0;
} PaintContext;

PaintContext* paint_context_create(sfRenderWindow* window);
void paint_context_destroy(PaintContext* self);
void paint_context_draw_rect(PaintContext* self, sfRectangleShape* shape);
void paint_context_draw_on_window(PaintContext* self);
#endif //PAINT_CONTEXT_H
