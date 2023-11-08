#include <malloc.h>
#include "../include/Player.h"
#include "../include/Workshop.h"

static int player_setup(player_t *player) {
    // Create Player Sprite, Texture and Clock
    player->is_moving = false;
    if (player->sprite == NULL || player->texture == NULL || player->animation_clock == NULL)
        return 84;
    // Setup Player Texture, Sprite
    return 0;
}

static int game_setup(game_t *game) {
    // Setup RenderWindow
    if (game->game_window == NULL || player_setup(game->player) != 0)
        return 84;
    // Setup FrameLimit the RenderWindow
    return 0;
}

int launch() {
    game_t game = {};
    // Initialize Player
    if (game.player == NULL || game_setup(&game) == 84)
        return 84;
    return game_loop(&game);
}