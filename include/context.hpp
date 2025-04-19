#ifndef CONTEXT_HPP
#define CONTEXT_HPP
#include "structs.hpp"
#include <SDL3/SDL.h>
#include <iostream>
#include <memory>

class Context {
private:
    struct DeleteWindow {
        void operator()(SDL_Window *window) { SDL_DestroyWindow(window); }
    };
    struct DeleteRenderer {
        void operator()(SDL_Renderer *renderer) {
            SDL_DestroyRenderer(renderer);
        }
    };

public:
    Context() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize! SDL_Error: "
                      << SDL_GetError() << std::endl;
            exit(1);
        }

        window = std::unique_ptr<SDL_Window, DeleteWindow>(
            SDL_CreateWindow("Game Loop", WINDOW_WIDTH, WINDOW_HEIGHT, 0),
            DeleteWindow());

        if (!window) {
            std::cerr << "Window could not be created! SDL_Error: "
                      << SDL_GetError() << std::endl;
            exit(1);
        }

        renderer = std::unique_ptr<SDL_Renderer, DeleteRenderer>(
            SDL_CreateRenderer(window.get(), nullptr), DeleteRenderer());

        if (!renderer) {
            exit(1);
        }
    }

    SDL_Window *getWindow() const { return window.get(); }
    SDL_Renderer *getRenderer() const { return renderer.get(); }

    ~Context() { SDL_Quit(); }

private:
    // NOTE: must declare renderer after window so cleaned up before window
    std::unique_ptr<SDL_Window, DeleteWindow> window;
    std::unique_ptr<SDL_Renderer, DeleteRenderer> renderer;
};

#endif
