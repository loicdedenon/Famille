/**
 * @file 
 * @author Eric Vantillard
 * @date 13/03/2024
 * @copyright Copyright (c) 2024 Eric Vantillard. All rights reserved.
 */

#ifndef PAINT_STATE_H
#define PAINT_STATE_H

#include "paint_context.h"

#include <SFML/Window/Event.h>

typedef enum PaintState {
    PAINT_STATE_IDLE,
    PAINT_STATE_DRAW_RECTANGLE,
} PaintState;

PaintState paint_state_handle_event(PaintState state, PaintContext *context, sfEvent event);
PaintState paint_handle_events_on_idle(PaintContext *context, sfEvent event);
PaintState paint_handle_events_on_draw_rect(PaintContext *context, sfEvent event);

#endif //PAINT_STATE_H
