#include "../include/chunk.hpp"
#include "../include/config.hpp"
#include "../include/player.hpp"
#include <SDL3/SDL.h>
#include <iostream>

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

    SDL_Window *window = SDL_CreateWindow("Game Loop", Config::windowWidth,
                                          Config::windowHeight, 0);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
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

    Chunk chunk(0, 0);
    for (int i = 0; i < 10; i++) {
        Block *block =
            new Block(Config::randInt(0, 1000), Config::randInt(0, 1000),
                      Config::randInt(30, 300), Config::randInt(30, 300),
                      Color(Config::randInt(0, 255), Config::randInt(0, 255),
                            Config::randInt(0, 255)),
                      renderer);
        chunk.addBlock(block);
    }

    while (running) {
        // handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EventType::SDL_EVENT_QUIT) {
                running = false;
            }
            if (event.type == SDL_EventType::SDL_EVENT_KEY_DOWN &&
                event.key.scancode == SDL_SCANCODE_ESCAPE) {
                running = false;
            }
        }

        player.update();

        setBackground(renderer);
        chunk.draw();
        player.draw();

        renderScreen(renderer);
    }
    cleanup(renderer, window);
    return 0;
}
