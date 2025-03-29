#include "../include/config.hpp"
#include "../include/player.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <iostream>
#include <ranges>

void cleanup(SDL_Renderer *renderer, SDL_Window *window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void setBackground(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);
}

void renderScreen(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer);
    SDL_Delay(Config::fpsDelay);
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
                  << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "SDL2 Game Loop", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        Config::windowWidth, Config::windowHeight, SDL_WINDOW_SHOWN);
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

    Player player(20, 20, 10, renderer, Color(255, 0, 0, 255));

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

        player.update();

        setBackground(renderer);
        player.draw();

        renderScreen(renderer);
    }
    cleanup(renderer, window);
    return 0;
}
