#ifndef GAME_CONTENT_HPP
#define GAME_CONTENT_HPP

#include "chunk.hpp"
#include "player.hpp"
#include "screen_content.hpp"
#include <SDL3/SDL_render.h>

class GameContent {
public:
    GameContent(SDL_Renderer *renderer)
        : pos(0, 0), screen(0, 0),
          player(20, 20, 10, renderer, Color(255, 0, 0, 255),
                 [this](Vector2 change) { this->pos = this->pos + change; }

          ) {

        Chunk *chunk = new Chunk(0, 0, Config::chunkSize);
        for (int i = 0; i < 20; i++) {
            Block *block = new Block(
                Config::randInt(0, 1000), Config::randInt(0, 1000),
                Config::randInt(30, 300), Config::randInt(30, 300),
                Color(Config::randInt(0, 255), Config::randInt(0, 255),
                      Config::randInt(0, 255)),
                renderer);
            chunk->addBlock(block);
        }
        screen.addChunk(chunk);
    }

    void update() {
        screen.update();
        player.update();
    }
    void draw() const {
        screen.draw(pos.x, pos.y);
        player.draw(0, 0);
    }

private:
    Vector2 pos;
    ScreenContent screen;
    Player player;
};

#endif
