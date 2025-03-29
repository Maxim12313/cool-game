#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "block.hpp"
#include "config.hpp"
#include "structs.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

class Player : public Block {
public:
    Player(int width, int height, int speed, SDL_Renderer *renderer,
           Color color)
        : Block(Config::windowWidth / 2 - width / 2,
                Config::windowHeight / 2 - height / 2, width, height, color,
                renderer),
          speed(speed) {}

    void update() {
        const bool *keystate = SDL_GetKeyboardState(NULL);

        SDL_FRect rect = getRect();
        if (keystate[SDL_SCANCODE_W])
            rect.y -= speed;
        if (keystate[SDL_SCANCODE_S])
            rect.y += speed;
        if (keystate[SDL_SCANCODE_A])
            rect.x -= speed;
        if (keystate[SDL_SCANCODE_D])
            rect.x += speed;

        setRect(rect);
    }

private:
    int speed;
};

#endif
