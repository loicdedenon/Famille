/**
 * @file 
 * @author Eric Vantillard
 * @date 13/03/2024
 * @copyright Copyright (c) 2024 Eric Vantillard. All rights reserved.
 */

#include "paint_state.h"

#include <stdlib.h>

#include "paint_context.h"
#include "sfml_utils.h"

#include <SFML/Window/Event.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>

#define UNUSED(x) (void)(x)
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

PaintState paint_state_handle_event(PaintState state, PaintContext *context, sfEvent event) {
    switch (state) {
        case PAINT_STATE_IDLE:
            return paint_handle_events_on_idle(context, event);
        case PAINT_STATE_DRAW_RECTANGLE:
            return paint_handle_events_on_draw_rect(context, event);
        default:
            return paint_handle_events_on_idle(context, event);
    }
}

PaintState paint_handle_events_on_idle(PaintContext *context, sfEvent event) {
    UNUSED(context);
    if (is_key_pressed(event, sfKeyR)) {
        return PAINT_STATE_DRAW_RECTANGLE;
    }
    return PAINT_STATE_IDLE;
}

PaintState paint_handle_events_on_draw_rect(PaintContext *context, sfEvent event) {
    //TODO draw rectangle
    if (is_key_pressed(event, sfKeyEscape)) {
        return PAINT_STATE_IDLE;
    }
    if_click(context->window, event);
    sfVector2i pos;
    if (is_mouse_click(event, &pos)) {
        context->p0 = pos;
    } else if (is_mouse_released(event, &pos)) {
        int w = abs(pos.x - context->p0.x);
        int h = abs(pos.y - context->p0.y);
        int x = MIN(pos.x, context->p0.x);
        int y = MIN(pos.y, context->p0.y);
        if (w > 0 && h > 0) {
            sfRectangleShape *shape = create_rectangle(x, y, w, h, sfBlue);
            paint_context_draw_rect(context, shape);
            sfRectangleShape_destroy(shape);
        }
    }
    return PAINT_STATE_DRAW_RECTANGLE;
}


