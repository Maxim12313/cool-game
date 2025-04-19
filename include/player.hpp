#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "structs.hpp"
#include "vec2.hpp"
#include <SDL3/SDL_render.h>
#include <iostream>

struct Player {
    Vec2 pos;
    float speed = 10;
    Color color;
    Player() : color(0, 0, 100) {}

    void draw(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_FRect rect(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 75, 75);
        SDL_RenderFillRect(renderer, &rect);
    }

    void handleInput() {
        const bool *keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_W])
            pos.y -= speed;
        if (keystate[SDL_SCANCODE_S])
            pos.y += speed;
        if (keystate[SDL_SCANCODE_A])
            pos.x -= speed;
        if (keystate[SDL_SCANCODE_D])
            pos.x += speed;
        // std::cout << to_string(pos) << "\n";
    }
};

#endif
