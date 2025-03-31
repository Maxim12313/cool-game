#ifndef GAME_HPP
#define GAME_HPP
#include "config.hpp"
#include "structs.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>

struct Game {
    bool running;
    SDL_Renderer *renderer;
    SDL_Window *window;

    Vector2 offset;
    Player player;
    GameRects gameRects;

    Game();

    void renderScreen() {
        SDL_RenderPresent(renderer);
        SDL_Delay(Config::fpsDelay);
    }

    ~Game() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};

void gameLoop();

void handleInput(Game &game, SDL_Event &event);
void handleDrawing(Game &game);

#endif
