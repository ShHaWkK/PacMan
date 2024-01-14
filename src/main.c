#include <stdio.h>

#include "../include/game.h"
#include "../include/mouse.h"

int main(int argc, char**argv) {
    Game game;
    initGame(&game);

    while (game.isRunning) {
        while (SDL_PollEvent(&game.event)) {
            if (game.event.type == SDL_QUIT) {
                game.isRunning = 0;
            } else {
                handleKeyboardInput(&game, &game.event);
            }
        }
        updateGame(&game);
        drawGame(&game);
    }

    closeGame(&game);
    return 0;
}
