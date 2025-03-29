#include "../include/player.hpp"
#include "../include/config.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

Player::Player(int width, int height, int speed, SDL_Renderer *renderer,
               Color color)
    : GameBlock(Config::windowWidth / 2 - width / 2,
                Config::windowHeight / 2 - height / 2, width, height, color,
                renderer),
      speed(speed) {
}

void Player::update() {
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    SDL_Rect rect = getRect();
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
