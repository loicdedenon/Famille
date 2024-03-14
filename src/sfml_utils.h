/**
 * @file 
 * @author Eric Vantillard
 * @date 13/03/2024
 * @copyright Copyright (c) 2024 Eric Vantillard. All rights reserved.
 */

#ifndef SFML_UTILS_H
#define SFML_UTILS_H

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

sfBool is_key_pressed(sfEvent event, sfKeyCode code);

sfBool is_mouse_click(sfEvent event, sfVector2i *pos);

sfBool is_mouse_released(sfEvent event, sfVector2i *pos);

sfBool if_click(sfRenderWindow* window, sfEvent event);

sfRectangleShape *create_rectangle(int x, int y, int w, int h, sfColor fill_color);

#endif //SFML_UTILS_H
