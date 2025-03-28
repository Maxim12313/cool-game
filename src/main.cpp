#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_scancode.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int RECT_SIZE = 50;
const int SPEED = 5;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
                  << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "SDL2 Game Loop", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // position
    SDL_Rect rect = {SCREEN_WIDTH / 2 - RECT_SIZE / 2,
                     SCREEN_HEIGHT / 2 - RECT_SIZE / 2, RECT_SIZE, RECT_SIZE};

    bool running = true;
    SDL_Event event;

    while (running) {
        // handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                running = false;
            }
        }

        // Keyboard state
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_W])
            rect.y -= SPEED;
        if (keystate[SDL_SCANCODE_S])
            rect.y += SPEED;
        if (keystate[SDL_SCANCODE_A])
            rect.x -= SPEED;
        if (keystate[SDL_SCANCODE_D])
            rect.x += SPEED;
        if (keystate[SDL_SCANCODE_ESCAPE])
            running = false;

        // clear screen
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_RenderClear(renderer);

        // draw rectangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        // present renderer
        SDL_RenderPresent(renderer);

        // delay for frame rate control
        SDL_Delay(16);
    }

    // cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
