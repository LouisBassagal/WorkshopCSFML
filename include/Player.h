//
// Created by kane on 03/11/23.
//

#ifndef WORKSHOPCSFML_PLAYER_H
#define WORKSHOPCSFML_PLAYER_H

#include <SFML/Graphics.h>
#include <stdbool.h>

static const char *PLAYER_TEXTURE = "./assets/Sonic.png";
static const sfIntRect IDLE_RECT = {0, 0, 48, 48};
static const sfIntRect RUN_RECT = {48, 48, 48, 48};

typedef enum direction_s {
    RIGHT,
    LEFT
} direction_t;

typedef struct player_s{
    sfSprite *sprite;
    sfTexture *texture;

    sfIntRect texture_rect;
    sfClock *animation_clock;

    direction_t facing;
    bool is_moving;
} player_t;


#endif //WORKSHOPCSFML_PLAYER_H
