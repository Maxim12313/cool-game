#include "../include/game_block.hpp"
#include <SDL3/SDL_render.h>

GameBlock::GameBlock(int x, int y, int width, int height, Color color,
                     SDL_Renderer *renderer)
    : x(x), y(y), color(color), renderer(renderer), rect(x, y, width, height) {
}

void GameBlock::draw() const {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}
