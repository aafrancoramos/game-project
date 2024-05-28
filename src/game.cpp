#include "../headers/game.h"
#include <iostream>

using namespace std;

game::game() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer);
    SDL_SetWindowTitle(window, "Game");

    loop = true;
}

void game::gameLoop() {
    while(loop){
        while(SDL_PollEvent(&e) > 0) {
            switch (e.type)
            {
            case SDL_QUIT:
                loop = false;
                break;
            }
        }
    }
}

game::~game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}