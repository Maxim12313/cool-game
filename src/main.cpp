#include "../include/structs.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <iostream>

void setBackground(SDL_Renderer *renderer);
void renderScreen(SDL_Renderer *renderer);
void cleanup(SDL_Renderer *renderer, SDL_Window *window);
bool input();

int main() {

    // auto p = init();
    // SDL_Window *window = p.window.get();
    // SDL_Renderer *renderer = p.renderer.get();
    //
    // while (input()) {
    //     setBackground(renderer);
    //     renderScreen(renderer);
    // }
    // cleanup(renderer, window);
}

void setBackground(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);
}

void renderScreen(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
}

void cleanup(SDL_Renderer *renderer, SDL_Window *window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return false;
        }
        if (event.type == SDL_EVENT_KEY_DOWN &&
            event.key.scancode == SDL_SCANCODE_ESCAPE) {
            return false;
        }
    }
    return true;
}
