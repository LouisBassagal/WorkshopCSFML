#include "../include/Workshop.h"

int game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->game_window)) {
        sfRenderWindow_clear(game->game_window, sfBlack);
        event_manager(game);
        player_manager(game->player);
        sfRenderWindow_drawSprite(game->game_window, game->player->sprite, NULL);
        sfRenderWindow_display(game->game_window);
    }
    destroy_resources(game);
    return 0;
}