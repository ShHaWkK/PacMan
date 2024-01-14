#ifndef GAME_H
#define GAME_H

#define MAX_GHOSTS 4
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PACMAN_TEXTURE_PATH "assets/texture/pacman.png"
#define GHOST_TEXTURE_PATH "assets/texture/ghost.png"

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
typedef struct {
    int x, y;       // Position
    int dx, dy;     // Direction de déplacement
    SDL_Texture* texture;
} Entity;

// Structure pour l'état du jeu
typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    int isRunning;
    Entity pacman;
    Entity ghosts[MAX_GHOSTS];
    TTF_Font* font;
    Mix_Chunk* eatSound;
    // Autres éléments de jeu (score, niveau, etc.)
} Game;

void initGame(Game *game);
void updateGame(Game *game);
void drawGame(Game *game);
void closeGame(Game *game);
void moveEntity(Entity *entity);

#endif // GAME_H
