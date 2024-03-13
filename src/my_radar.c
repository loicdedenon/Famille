/*
** EPITECH PROJECT, 2024
** my_paint.c
** File description:
** paint
*/
#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.h>

#define UNUSED(x) (void)(x)

void repair(sfRenderWindow* window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

static sfBool if_click(sfRenderWindow* window, sfEvent event)
{
    sfBool clicked = sfFalse;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x >= 816 && mouse.x <= 1062) {
        if (mouse.y >= 526 && mouse.y <= 594)
            clicked = sfTrue;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        printf("x:,%d y: %d, button: %d\n", event.mouseButton.x, event.mouseButton.y, event.mouseButton.button);
    }
    return clicked;
}

typedef enum PaintState {
    PAINT_STATE_IDLE,
    PAINT_STATE_DRAW_RECTANGLE,
}PaintState;

typedef struct PaintContext {
    sfRenderWindow* window;
    sfRenderTexture* buffer;
} PaintContext;

PaintContext* paint_context_create(sfRenderWindow* window) {
    PaintContext* result = malloc(sizeof(PaintContext));
    result->window=window;
    sfVector2u size = sfRenderWindow_getSize(window);
    result->buffer = sfRenderTexture_create(size.x, size.y,sfFalse);
    sfRenderTexture_clear(result->buffer,sfTransparent);
    return result;
}

void paint_context_destroy(PaintContext* self) {
    if(self != NULL) {
        self->window=NULL;
        sfRenderTexture_destroy(self->buffer);
        self->buffer=NULL;
        free(self);
    }
}

void paint_context_draw_rect(PaintContext* self, sfRectangleShape* shape) {
    sfRenderTexture_drawRectangleShape(self->buffer,shape,NULL);
}

void paint_context_draw_on_window(PaintContext* self) {
    sfRenderTexture_display(self->buffer);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite,sfRenderTexture_getTexture(self->buffer),sfTrue);
    sfRenderWindow_drawSprite(self->window,sprite,NULL);
    sfSprite_destroy(sprite);
}

static sfBool is_key_pressed(sfEvent event, sfKeyCode code) {
    return  event.type == sfEvtKeyPressed && event.key.code == code;
}

PaintState paint_handle_events_on_idle(PaintContext* context,sfEvent event) {
    UNUSED(context);
    if (is_key_pressed( event,sfKeyR)) {
         return PAINT_STATE_DRAW_RECTANGLE;
     }
    return PAINT_STATE_IDLE;
}

static sfRectangleShape* create_rectangle(int x,int y, int w, int h, sfColor fill_color) {
    sfRectangleShape *object = sfRectangleShape_create();
    sfVector2f position = {x,y};
    sfRectangleShape_setPosition(object, position);
    sfVector2f size = {w,h};
    sfRectangleShape_setSize(object, size);
    sfRectangleShape_setFillColor(object,fill_color);
    return object;
}
PaintState  paint_handle_events_on_draw_rect(PaintContext* context,sfEvent event) {
    //TODO draw rectangle
    if(is_key_pressed(event,sfKeyEscape)) {
        return PAINT_STATE_IDLE;
    }
    if_click(context->window,event);
    sfRectangleShape *object = create_rectangle(560,580,50,50,sfBlue);
    paint_context_draw_rect(context,object);
    sfRectangleShape_destroy(object);
    return PAINT_STATE_DRAW_RECTANGLE;
}

PaintState paint_handle_event(PaintState state, PaintContext* context,sfEvent event) {
    switch (state) {
        case PAINT_STATE_IDLE:
            return paint_handle_events_on_idle(context,event);
        case PAINT_STATE_DRAW_RECTANGLE:
            return paint_handle_events_on_draw_rect(context,event);
        default:
            return paint_handle_events_on_idle(context,event);
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

void fenetre()
{
    sfEvent event;
    sfRenderWindow *window;
    sfTexture *texture = sfTexture_createFromFile
    ("Votre texte de paragraphe.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVideoMode video_mode = {1920, 1080, 32};
    sfVector2f scale = {1, 1};

    window = sfRenderWindow_create(video_mode,"#myradar", sfDefaultStyle, NULL);
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
            //if_click(window, event);
            paint_state = paint_handle_event(paint_state, paint_context, event);
        }
    }

    paint_context_destroy(paint_context);
    sfRenderWindow_destroy(window);
}
