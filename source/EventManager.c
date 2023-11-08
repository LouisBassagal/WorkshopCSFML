#include "../include/Workshop.h"

void event_manager(game_t *game) {
    sfEvent event = {};

    while (sfRenderWindow_pollEvent(game->game_window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->game_window);
    }
}