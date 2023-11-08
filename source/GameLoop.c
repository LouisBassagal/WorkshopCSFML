#include "../include/Workshop.h"

int game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->game_window)) {
        // Clear the Window
        event_manager(game);
        player_manager(game->player);
        // Draw sprite in the window and display it
    }
    destroy_resources(game);
    return 0;
}