#ifndef WORKSHOPCSFML_WORKSHOP_H
#define WORKSHOPCSFML_WORKSHOP_H

#include <SFML/Window.h>
#include "Player.h"

typedef struct game_s {
    sfRenderWindow *game_window;
    player_t *player;
} game_t;

int launch();
int game_loop(game_t *game);
void event_manager(game_t *game);
void player_manager(player_t *player);
void destroy_resources(game_t *game);

#endif //WORKSHOPCSFML_WORKSHOP_H
