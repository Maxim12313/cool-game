#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "block.hpp"
#include "config.hpp"
#include "structs.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <functional>

class Player : public Block {
public:
    Player(int width, int height, float speed, SDL_Renderer *renderer,
           Color color, std::function<void(Vector2)> moveCallback)
        : Block(Config::windowWidth / 2 - width / 2,
                Config::windowHeight / 2 - height / 2, width, height, color,
                renderer),
          moveCallback(moveCallback), speed(speed) {}

    void update() {
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

        change = change.normalized() * speed;
        moveCallback(change);
    }

private:
    float speed;
    std::function<void(Vector2)> moveCallback;
};

#endif
