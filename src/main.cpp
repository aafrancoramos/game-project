#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include "../headers/game.h"

int main(int argc, char* argv[]) {
    game g;
    g.gameLoop();
    
    return 0;
}
