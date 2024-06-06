#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Entity {
public:
    Entity();
    ~Entity();

    void initialize(SDL_Renderer* renderer, const char* filePath, int x, int y);
    
    void draw(SDL_Renderer* renderer);
    
    void handleEvent(SDL_Event& e);
    
    void update(float deltaTime);

private:
    SDL_Texture* texture;
    SDL_Rect src, dst;

    float posX, posY;
    float velocityX, velocityY;
    bool movingUp, movingDown, movingLeft, movingRight;

    void setVelocity();
};

#endif
