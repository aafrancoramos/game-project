#include <SDL2/SDL.h>

class game {
    public:
        game();

        ~game();

        void gameLoop();

    private:
        const int SCREEN_WIDTH = 300;
        const int SCREEN_HEIGHT = 300;

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event e;

        bool loop;
};