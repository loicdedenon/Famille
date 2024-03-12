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

typedef enum PaintState {
    PAINT_STATE_IDLE,
    PAINT_STATE_DRAW_RECTANGLE,
}PaintState;

typedef struct PaintContext {
    sfRenderWindow* window;
    unsigned int window_width;
    unsigned int window_height;
} PaintContext;

PaintContext* paint_context_create(sfRenderWindow* window) {
    PaintContext* result = (PaintContext*) malloc(sizeof(PaintContext));
    result->window=window;
    sfVector2u size = sfRenderWindow_getSize(window);
    result->window_width = size.x;
    result->window_height = size.y;
    return result;
}
void paint_context_destroy(PaintContext* self) {
    if(self != NULL) {
        self->window=NULL;
        self->window_width=0;
        self->window_height=0;
        free(self);
    }
}

PaintState paint_handle_event_on_idle(PaintContext* context,sfEvent event) {
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR) {
         return PAINT_STATE_DRAW_RECTANGLE;
     }else{
         return PAINT_STATE_IDLE;
    }
}

PaintState  paint_handle_event_on_draw_rect(PaintContext* context,sfEvent event) {
    sfRenderWindow* window = context->window;
    //context->window_width
    //context->window_height
    //TODO draw rectangle
    if_click(window,event);
    //sfRenderWindow_drawRectangleShape();
    return PAINT_STATE_DRAW_RECTANGLE;
}

PaintState paint_handle_event(PaintState state, PaintContext* context,sfEvent event) {
    switch (state) {
        case PAINT_STATE_IDLE:
            return paint_handle_event_on_idle(context,event);
        case PAINT_STATE_DRAW_RECTANGLE:
            return paint_handle_event_on_draw_rect(context,event);
        default:
            return paint_handle_event_on_idle(context,event);
    }
}
//
//
// typedef paint_state(*event_handler)(sfRenderWindow*,sfEvent);
//
// paint_state idle_state_handler(sfRenderWindow *window, sfEvent event) {
//     if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR) {
//         return (drawing_rectangle);
//     }else{
//         return (idle_state);
//     }
// }
// paint_state drawing_rectangle_handler(sfRenderWindow *window, sfEvent event) {
//     if( event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
//     sfTexture *rectangle2 = sfRectangleShape_create();
//     sfVector2f scale2 = {1,1};
//     sfVector2f position = {event.mouseButton.x, event.mouseButton.y};
//
//         sfRectangleShape_setScale(rectangle2,scale2);
//         sfRectangleShape_setPosition(rectangle2,position);
//         sfRenderWindow_drawRectangleShape(window,rectangle2,NULL);
//         sfRectangleShape_destroy(rectangle2);
//     }
// }

int fenetre()
{
    sfEvent event;
    sfRenderWindow *window;
    sfTexture *texture = sfTexture_createFromFile
    ("Votre texte de paragraphe.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVideoMode video_mode = {1920, 1080, 32};
    sfVector2f scale = {1, 1};
    //event_handler current_handler = idle_state_handler;

    window = sfRenderWindow_create(video_mode,
    "#myradar", sfDefaultStyle, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);

    PaintState paint_state = PAINT_STATE_IDLE;
    PaintContext *paint_context =  paint_context_create(window);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            repair(window, event);
            //if_click(window, event);
            paint_state = paint_handle_event(paint_state, paint_context, event);
        }
    }

    paint_context_destroy(paint_context);
    sfRenderWindow_destroy(window);
}
