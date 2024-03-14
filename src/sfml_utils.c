/**
 * @file 
 * @author Eric Vantillard
 * @date 13/03/2024
 * @copyright Copyright (c) 2024 Eric Vantillard. All rights reserved.
 */

#include "sfml_utils.h"

#include <stdio.h>

#include <SFML/Config.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>

sfBool is_key_pressed(sfEvent event, sfKeyCode code) {
    return event.type == sfEvtKeyPressed && event.key.code == code;
}

sfBool is_mouse_click(sfEvent event, sfVector2i *pos) {
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
        pos->x = event.mouseButton.x;
        pos->y = event.mouseButton.y;
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_mouse_released(sfEvent event, sfVector2i *pos) {
    if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button == sfMouseLeft) {
        pos->x = event.mouseButton.x;
        pos->y = event.mouseButton.y;
        return sfTrue;
    }
    return sfFalse;
}

sfBool if_click(sfRenderWindow *window, sfEvent event) {
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

sfRectangleShape *create_rectangle(int x, int y, int w, int h, sfColor fill_color) {
    sfRectangleShape *object = sfRectangleShape_create();
    sfVector2f position = {x, y};
    sfRectangleShape_setPosition(object, position);
    sfVector2f size = {w, h};
    sfRectangleShape_setSize(object, size);
    sfRectangleShape_setFillColor(object, fill_color);
    return object;
}
