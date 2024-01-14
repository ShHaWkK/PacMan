#ifndef GAME_H
#define GAME_H

#define MAX_GHOSTS 4
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
typedef struct {
    int x, y;       // Position
    int dx, dy;     // Direction de déplacement
} Entity;

// Structure pour l'état du jeu
typedef struct {
    int isRunning;
    Entity pacman;
    Entity ghosts[MAX_GHOSTS];
    // Autres éléments de jeu (score, niveau, etc.)
} Game;

void initGame(Game *game);
void updateGame(Game *game);
void drawGame(const Game *game);
void closeGame(Game *game);
void moveEntity(Entity *entity);

#endif // GAME_H
