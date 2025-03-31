#include "../include/game.hpp"
#include <SDL3/SDL.h>

void handleInput(Game &game, SDL_Event &event) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EventType::SDL_EVENT_QUIT) {
            game.running = false;
        }
        if (event.type == SDL_EventType::SDL_EVENT_KEY_DOWN &&
            event.key.scancode == SDL_SCANCODE_ESCAPE) {
            game.running = false;
        }
    }

    const bool *keystate = SDL_GetKeyboardState(NULL);
    Vector2 change;
    if (keystate[SDL_SCANCODE_W])
        change.y += 1;
    if (keystate[SDL_SCANCODE_S])
        change.y -= 1;
    if (keystate[SDL_SCANCODE_A])
        change.x += 1;
    if (keystate[SDL_SCANCODE_D])
        change.x -= 1;

    // could just make a table because frequent computation
    change = change.normalize() * game.player.speed;
    game.offset = game.offset + change;
}
