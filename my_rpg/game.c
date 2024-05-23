/*
** EPITECH PROJECT, 2023
** game.c
** File description:
** title
*/

#include "../include/my.h"
#include "../include/struct.h"

void move_char(sfSprite *char_s, sfVector2f *char_pos, sfIntRect *char_rect, sfClock *clock)
{
    float animation = 1.0 / 4;
    float time = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    int frame = (int)(time / animation) % 4;
    char_rect->left = frame * char_rect->width;

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        char_pos->y -= 0.16;
        char_rect->top = 3 * char_rect->height;
    }
    else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        char_pos->y += 0.16;
        char_rect->top = 0;
    }
    else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        char_pos->x += 0.16;
        char_rect->top = 2 * char_rect->height;
    }
    else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        char_pos->x -= 0.16;
        char_rect->top = char_rect->height;
    }

    sfSprite_setTextureRect(char_s, *char_rect);
    sfSprite_setPosition(char_s, *char_pos);
}

void game_function(sfRenderWindow *window, sfEvent event)
{
    sfTexture *floot_t = sfTexture_createFromFile("./sprites/argenta.png", NULL);
    sfSprite *floor_s = sfSprite_create();
    sfVector2f scale = {2.5, 1.7};

    sfTexture *char_t = sfTexture_createFromFile("./sprites/main_char.png", NULL);
    sfSprite *char_s = sfSprite_create();
    sfVector2f char_pos = {850, 950};
    sfIntRect char_rect = {0, 0, 65, 65};

    sfMusic *musique = sfMusic_createFromFile("musique/main_game_song_1.ogg");
    sfMusic_play(musique);
    sfMusic_setLoop(musique,sfTrue);
    sfMusic_getLoop(musique);

    sfSprite_setTexture(floor_s, floot_t, sfTrue);
    sfSprite_setScale(floor_s, scale);
    sfSprite_getLocalBounds(char_s);
    sfSprite_getLocalBounds(floor_s);
    sfSprite_setTexture(char_s, char_t, sfTrue);
    sfSprite_setTextureRect(char_s, char_rect);
    sfSprite_setPosition(char_s, char_pos);

    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }

        }
        move_char(char_s, &char_pos, &char_rect, clock);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, floor_s, NULL);
        sfRenderWindow_drawSprite(window, char_s, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(musique);
    sfClock_destroy(clock);
}
