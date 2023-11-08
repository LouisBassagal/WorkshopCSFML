#include "../include/Workshop.h"
#include <stdio.h>

static void player_movement(player_t *player) {
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        // Move the player to the left
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        // Move the player to the right
        return;
    }
    player->is_moving = false;
}

static void player_animation(player_t *player) {
    sfIntRect rect;

    sfSprite_setScale(player->sprite, (player->facing == RIGHT) ?
                                      (sfVector2f){5, 5} : (sfVector2f){-5, 5});
    if (player->is_moving == false) {
        // Set the player's sprite to its idle pose
    }
    if (player->is_moving && sfSprite_getTextureRect(player->sprite).top != 48)
        sfSprite_setTextureRect(player->sprite, RUN_RECT);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(player->animation_clock)) > 75) {
        // Set the texture recto to the next frame of animation
        // Reset the animation clock
    }
}

void player_manager(player_t *player) {
    player_movement(player);
    player_animation(player);
}