#include "../include/mouse.h"

void handleKeyboardInput(Game *game, SDL_Event *event) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
            case SDLK_UP:
                game->pacman.dy = -1; game->pacman.dx = 0;
                break;
            case SDLK_DOWN:
                game->pacman.dy = 1; game->pacman.dx = 0;
                break;
            case SDLK_LEFT:
                game->pacman.dx = -1; game->pacman.dy = 0;
                break;
            case SDLK_RIGHT:
                game->pacman.dx = 1; game->pacman.dy = 0;
                break;
            default:
                break;
        }
    }
}
