#include "../include/Workshop.h"

void event_manager(game_t *game) {
    sfEvent event = {};

    while (sfRenderWindow_pollEvent(game->game_window, &event)) {
        // Close the window if the event close is detected (sfEvtClosed)
    }
}