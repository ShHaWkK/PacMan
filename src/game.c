#include "../include/game.h"


void initGame(Game *game) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    game->window = SDL_CreateWindow("Pac-Man", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    game->isRunning = 1;

    // Initialiser Pac-Man, les fantômes, charger les textures, sons, etc.

    // Charger la texture de Pac-Man
    SDL_Surface* tempSurface = IMG_Load(PACMAN_TEXTURE_PATH);
    game->pacman.texture = SDL_CreateTextureFromSurface(game->renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    // Charger les textures des fantômes
    tempSurface = IMG_Load(GHOST_TEXTURE_PATH);
    for (int i = 0; i < MAX_GHOSTS; i++) {
        game->ghosts[i].texture = SDL_CreateTextureFromSurface(game->renderer, tempSurface);
    }

    // Charger la texture du logo
    tempSurface = IMG_Load(LOGO_TEXTURE_PATH);
    game->logo.texture = SDL_CreateTextureFromSurface(game->renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    SDL_FreeSurface(tempSurface);
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
    //  couleur de fond
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    // Dessiner le logo
    SDL_Rect logoRect = {100, 50, 600, 200}; // Position et taille du logo
    SDL_RenderCopy(game->renderer, game->logo.texture, NULL, &logoRect);


    // Dessiner Pac-Man
    SDL_Rect pacmanRect = {game->pacman.x, game->pacman.y, 32, 32}; //  32x32 pixels
    SDL_RenderCopy(game->renderer, game->pacman.texture, NULL, &pacmanRect);

    // Ghost
    for (int i = 0; i < MAX_GHOSTS; i++) {
        SDL_Rect ghostRect = {game->ghosts[i].x, game->ghosts[i].y, 32, 32};
        SDL_RenderCopy(game->renderer, game->ghosts[i].texture, NULL, &ghostRect);
    }

    // Mettre à jour l'écran
    SDL_RenderPresent(game->renderer);
}


void closeGame(Game *game) {
    // Libérer les textures, les sons, fermer les systèmes SDL

    SDL_DestroyTexture(game->pacman.texture);
    for (int i = 0; i < MAX_GHOSTS; i++) {
        SDL_DestroyTexture(game->ghosts[i].texture);
    }
    SDL_DestroyTexture(game->logo.texture);

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