#include "../include/game.h"


void initGame(Game *game) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    game->window = SDL_CreateWindow("Pac-Man", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    game->isRunning = 1;

    // Initialiser Pac-Man, les fantômes, charger les textures, sons, etc.

    game->font = TTF_OpenFont("path/to/font.ttf", 24);
    game->eatSound = Mix_LoadWAV("path/to/eat_sound.wav");
}

void handleEvents(Game *game) {
    while (SDL_PollEvent(&game->event)) {
        if (game->event.type == SDL_QUIT) {
            game->isRunning = 0;
        }
        // Gérer d'autres événements ici (comme les entrées clavier)
    }
}

void updateGame(Game *game) {
    // Mise à jour de la logique du jeu

    moveEntity(&game->pacman);
    // Déplacer les fantômes, gérer les collisions, etc.
}

void drawGame(Game *game) {
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255); // Fond noir
    SDL_RenderClear(game->renderer);

    // Dessiner les entités, le labyrinthe, etc.

    SDL_RenderPresent(game->renderer);
}

void closeGame(Game *game) {
    // Libérer les textures, les sons, fermer les systèmes SDL

    SDL_DestroyTexture(game->pacman.texture);
    for (int i = 0; i < MAX_GHOSTS; i++) {
        SDL_DestroyTexture(game->ghosts[i].texture);
    }

    Mix_FreeChunk(game->eatSound);
    TTF_CloseFont(game->font);

    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();

    game->isRunning = 0;
}

void moveEntity(Entity *entity) {
    entity->x += entity->dx;
    entity->y += entity->dy;
    // Ajouter une logique de déplacement plus complexe ici
}