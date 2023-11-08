#include "../include/Workshop.h"
#include <stdlib.h>

void destroy_resources(game_t *game)
{
    sfSprite_destroy(game->player->sprite);
    sfClock_destroy(game->player->animation_clock);
    sfTexture_destroy(game->player->texture);
    free(game->player);
    sfRenderWindow_destroy(game->game_window);
}