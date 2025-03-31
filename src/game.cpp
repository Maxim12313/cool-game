#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <iostream>

#include "../include/game.hpp"

void generate() {
}

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
                  << std::endl;
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow("Game Loop", Config::windowWidth,
                                          Config::windowHeight, 0);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    running = true;
    this->renderer = renderer;
    this->window = window;

    float length = 20;
    Color color = Color(255, 0, 0, 255);
    float speed = 10;
    player = Player(length, color, speed);

    for (int i = 0; i < 20; i++) {
        int x = Config::randInt(1, 255);
        int y = Config::randInt(1, 255);
        int w = Config::randInt(1, 255);
        int h = Config::randInt(1, 256);
        gameRects.rects.push_back(SDL_FRect(x * 5, y * 5, w * 2, h * 2));
        gameRects.colors.push_back(Color(x, y, h, w));
    }
}

void gameLoop() {
    Game game;
    SDL_Event event;
    while (game.running) {
        handleInput(game, event);
        handleDrawing(game);
        game.renderScreen();
    }
}
