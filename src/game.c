#include "../include/game.h"

void initGame(Game *game, const char* title, int width, int height) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    game->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

    game->isRunning = 1;

    // Charger les textures, initialiser les sons, etc.

    // Exemple d'initialisation de Pac-Man
    game->pacman.x = 100;
    game->pacman.y = 100;
    game->pacman.dx = 1;
    game->pacman.dy = 0;
    // Charger la texture de Pac-Man ici

    // Initialiser les fantômes...

    // Charger la police et les sons
    game->font = TTF_OpenFont("path/to/font.ttf", 24);
    game->eatSound = Mix_LoadWAV("path/to/eat_sound.wav");
}

void updateGame(Game *game) {
    // Mise à jour de la logique du jeu

    // Exemple de déplacement de Pac-Man
    moveEntity(&game->pacman);

    // Déplacer les fantômes...

    // Gérer les collisions, le score, etc.
}

void drawGame(Game *game) {
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255); // Fond noir
    SDL_RenderClear(game->renderer);

    // Dessiner Pac-Man, les fantômes, et le labyrinthe

    SDL_RenderPresent(game->renderer);
}

void closeGame(Game *game) {
    //
