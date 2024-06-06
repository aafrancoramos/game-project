#include "entity.h"

Entity::Entity() : texture(nullptr), posX(0), posY(0), velocityX(0), velocityY(0),
    movingUp(false), movingDown(false), movingLeft(false), movingRight(false) {}

Entity::~Entity() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Entity::initialize(SDL_Renderer* renderer, const char* filePath, int x, int y) {
    texture = IMG_LoadTexture(renderer, filePath);

    if (texture == nullptr) {
        std::cerr << "Error: Loading texture failed. SDL_Error: " << SDL_GetError() << std::endl;
    }

    src.x = 0;
    src.y = 0;
    src.w = 128;
    src.h = 128;

    dst.w = 128;
    dst.h = 128;
    posX = static_cast<float>(x);
    posY = static_cast<float>(y);
    dst.x = x;
    dst.y = y;
}

void Entity::draw(SDL_Renderer* renderer) {
    dst.x = static_cast<int>(posX);
    dst.y = static_cast<int>(posY);
    SDL_RenderCopy(renderer, texture, &src, &dst);
}

void Entity::handleEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_w: movingUp = true; break;
            case SDLK_s: movingDown = true; break;
            case SDLK_a: movingLeft = true; break;
            case SDLK_d: movingRight = true; break;
        }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_w: movingUp = false; break;
            case SDLK_s: movingDown = false; break;
            case SDLK_a: movingLeft = false; break;
            case SDLK_d: movingRight = false; break;
        }
    }
}

void Entity::update(float deltaTime) {
    setVelocity();

    posX += velocityX * deltaTime;
    posY += velocityY * deltaTime;
}

void Entity::setVelocity() {
    velocityX = 0;
    velocityY = 0;

    if (movingUp) {
        velocityY = -100;
    }
    if (movingDown) {
        velocityY = 100;
    }
    if (movingLeft) {
        velocityX = -100;
    }
    if (movingRight) {
        velocityX = 100;
    }
}
