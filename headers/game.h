#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "entity.h"

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    void processInput();
    
    void update(float deltaTime);
    
    void render();

    SDL_Window* window;
    SDL_Renderer* renderer;

    bool isRunning;
    
    Uint32 lastTicks;
    Entity player;

    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;
};

#endif
