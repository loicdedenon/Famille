/**
 * @file 
 * @author Eric Vantillard
 * @date 13/03/2024
 * @copyright Copyright (c) 2024 Eric Vantillard. All rights reserved.
 */
#include <stdio.h>
#include <stdlib.h>

#include <SFML/Config.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Event.h>

#include "sfml_utils.h"
#include "utils.h"

sfBool is_key_pressed(sfEvent event, sfKeyCode code) {
    return event.type == sfEvtKeyPressed && event.key.code == code;
}

sfBool is_mouse_clicked(sfEvent event, sfVector2i *pos) {
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

sfBool is_mouse_moved(sfEvent event, sfVector2i *pos) {
    if (event.type == sfEvtMouseMoved) {
        pos->x = event.mouseMove.x;
        pos->y = event.mouseMove.y;
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

sfRectangleShape *sfRectangleShape_create_from_coord(sfVector2i p0, sfVector2i p1) {
    int w = abs(p0.x - p1.x);
    int h = abs(p0.y - p1.y);
    int x = MIN(p0.x, p1.x);
    int y = MIN(p0.y, p1.y);
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f position = {x, y};
    sfRectangleShape_setPosition(rect, position);
    sfVector2f size = {w, h};
    sfRectangleShape_setSize(rect, size);
    return rect;
}

void sfRenderWindow_drawRenderedTexture(sfRenderWindow *window, sfRenderTexture *texture) {
    sfRenderTexture_display(texture);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, sfRenderTexture_getTexture(texture),sfTrue);
    sfRenderWindow_drawSprite(window, sprite,NULL);
    sfSprite_destroy(sprite);
}
