#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "game_block.hpp"
#include "structs.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

class Player : public GameBlock {
public:
    Player(int width, int height, int speed, SDL_Renderer *renderer,
           Color color);

    void update() override;

private:
    int speed;
};

#endif
