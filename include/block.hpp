#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "game_object.hpp"
#include "structs.hpp"
#include <SDL3/SDL.h>
#include <iostream>
#include <utility>

class Block : public GameObject {
public:
    Block(int x, int y, int width, int height, Color color,
          SDL_Renderer *renderer)
        : GameObject(x, y), width(width), height(height), color(color),
          renderer(renderer) {}

    virtual void update() {}

    void draw(int offX, int offY) const {
        SDL_FRect rect = SDL_FRect(offX + pos.x, offY + pos.y, width, height);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &rect);
    }

public:
    int width, height;

private:
    Color color;
    SDL_Renderer *renderer;
};

#endif
