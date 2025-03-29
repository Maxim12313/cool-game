#include "../include/player.hpp"
#include "../include/config.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

Player::Player(int size, int speed, SDL_Renderer *renderer, Color color)
    : size(size), speed(speed), color(color), renderer(renderer),
      rect(Config::windowWidth / 2 - size / 2,
           Config::windowWidth / 2 - size / 2, size, size) {
}

void Player::draw() {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Player::update() {
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_W])
        rect.y -= speed;
    if (keystate[SDL_SCANCODE_S])
        rect.y += speed;
    if (keystate[SDL_SCANCODE_A])
        rect.x -= speed;
    if (keystate[SDL_SCANCODE_D])
        rect.x += speed;
}
