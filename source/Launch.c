#include <malloc.h>
#include "../include/Player.h"
#include "../include/Workshop.h"

static int player_setup(player_t *player) {
    player->texture = sfTexture_createFromFile(PLAYER_TEXTURE, NULL);
    player->sprite = sfSprite_create();
    player->animation_clock = sfClock_create();
    player->facing = RIGHT;
    player->is_moving = false;
    if (player->sprite == NULL || player->texture == NULL || player->animation_clock == NULL)
        return 84;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, IDLE_RECT);
    sfSprite_setScale(player->sprite, (sfVector2f){5, 5});
    sfSprite_setOrigin(player->sprite, (sfVector2f){24.0F, 24.0F});
    sfSprite_setPosition(player->sprite, (sfVector2f){400, 300});
    return 0;
}

static int game_setup(game_t *game) {
    sfVideoMode videoMode = {800, 600, 32};
    game->game_window = sfRenderWindow_create(videoMode, "CSFMLWorkshop", sfResize | sfClose, NULL);
    if (game->game_window == NULL || player_setup(game->player) != 0)
        return 84;
    sfRenderWindow_setFramerateLimit(game->game_window, 60);
    return 0;
}

int launch() {
    game_t game = {};
    game.player = malloc(sizeof(player_t));
    if (game.player == NULL || game_setup(&game) == 84)
        return 84;
    return game_loop(&game);
}
