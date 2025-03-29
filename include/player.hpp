#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "structs.hpp"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class Player {
public:
    Player(int size, int speed, SDL_Renderer *renderer, Color color);
    void draw();
    void update();

private:
    int size;
    int speed;
    Color color;
    SDL_Renderer *renderer;
    SDL_Rect rect;
};

#endif
