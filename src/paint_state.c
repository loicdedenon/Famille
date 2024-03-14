/**
 * @file 
 * @author Eric Vantillard
 * @date 13/03/2024
 * @copyright Copyright (c) 2024 Eric Vantillard. All rights reserved.
 */

#include "paint_state.h"

#include "paint_context.h"
#include "sfml_utils.h"

#include <SFML/Window/Event.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>

#include "utils.h"

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
    if (is_mouse_clicked(event, &pos)) {
        context->p0 = pos;
        context->dragging = sfTrue;
    } else if (is_mouse_released(event, &pos)) {
        if (pos.x != context->p0.x && pos.y != context->p0.y) {
            sfRectangleShape *shape = sfRectangleShape_create_from_coord(context->p0, pos);
            sfRectangleShape_setFillColor(shape, sfGreen);
            sfRenderTexture_drawRectangleShape(context->buffer, shape,NULL);
            sfRenderTexture_clear(context->temp_buffer, sfTransparent);
            sfRectangleShape_destroy(shape);
        }
        context->dragging = sfFalse;
    } else if (context->dragging && is_mouse_moved(event, &pos)) {
        if (pos.x != context->p0.x && pos.y != context->p0.y) {
            sfRectangleShape *shape = sfRectangleShape_create_from_coord(context->p0, pos);
            sfRectangleShape_setFillColor(shape, sfBlue);
            sfRenderTexture_clear(context->temp_buffer, sfTransparent);
            sfRenderTexture_drawRectangleShape(context->temp_buffer, shape,NULL);
            sfRectangleShape_destroy(shape);
        }
    }
    return PAINT_STATE_DRAW_RECTANGLE;
}
