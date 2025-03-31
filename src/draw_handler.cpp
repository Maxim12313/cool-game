#include "../include/game.hpp"
#include "../include/structs.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

void drawRect(SDL_FRect &rect, Color &color, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}
void setBackground(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);
}

void handleDrawing(Game &game) {
    setBackground(game.renderer);

    GameRects &gameRects = game.gameRects;
    for (int i = 0; i < gameRects.rects.size(); i++) {
        SDL_FRect rect = gameRects.rects[i];
        rect.x += game.offset.x;
        rect.y += game.offset.y;
        drawRect(rect, gameRects.colors[i], game.renderer);
    }

    Player &player = game.player;
    drawRect(player.rect, player.color, game.renderer);
}
