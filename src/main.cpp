#include "../include/component_manager.hpp"
#include "../include/context.hpp"
#include "../include/entity_manager.hpp"
#include "../include/structs.hpp"
#include "../include/system_manager.hpp"
#include "../include/systems.hpp"
#include "../include/voxel.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <iostream>

void setBackground(SDL_Renderer *renderer);
void renderScreen(SDL_Renderer *renderer);
void cleanup(SDL_Renderer *renderer, SDL_Window *window);
bool input();

int main() {
    Context context;
    SDL_Renderer *renderer = context.getRenderer();
    SDL_Window *window = context.getWindow();

    VoxelRegion region;
    region.readFromInput();
    ActiveVoxelChunks active;
    for (VoxelChunk &chunk : region.chunks) {
        active.chunks.push_back(chunk);
    }

    EntityManager entityManager;
    ComponentManager componentManager;

    Entity player = entityManager.createEntity();

    while (input()) {
        setBackground(renderer);
        active.draw(renderer);
        renderScreen(renderer);
    }
}

void setBackground(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);
}

void renderScreen(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
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
