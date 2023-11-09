#include "../include/Workshop.h"
#include <stdio.h>

static void player_movement(player_t *player) {
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        player->is_moving = true;
        sfSprite_move(player->sprite, (sfVector2f){-5, 0});
        player->facing = LEFT;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        player->is_moving = true;
        sfSprite_move(player->sprite, (sfVector2f){5, 0});
        player->facing = RIGHT;
        return;
    }
    player->is_moving = false;
}

static void player_animation(player_t *player) {
    sfIntRect rect;

    sfSprite_setScale(player->sprite, (player->facing == RIGHT) ?
                                      (sfVector2f){5, 5} : (sfVector2f){-5, 5});
    if (player->is_moving == false) {
        sfSprite_setTextureRect(player->sprite, IDLE_RECT);
        return;
    }
    if (player->is_moving && sfSprite_getTextureRect(player->sprite).top != 48)
        sfSprite_setTextureRect(player->sprite, RUN_RECT);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(player->animation_clock)) > 75) {
        rect = sfSprite_getTextureRect(player->sprite);
        rect.left += 48;
        if (rect.left >= 384)
            rect.left = 0;
        sfSprite_setTextureRect(player->sprite, rect);
        sfClock_restart(player->animation_clock);
    }
}

void player_manager(player_t *player) {
    player_movement(player);
    player_animation(player);
}