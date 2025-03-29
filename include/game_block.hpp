#ifndef GAME_BLOCK_HPP
#define GAME_BLOCK_HPP

#include "structs.hpp"
#include <SDL3/SDL.h>
#include <utility>

class GameBlock {
public:
    GameBlock(int x, int y, int width, int height, Color color,
              SDL_Renderer *renderer);

    virtual void update() = 0;

    void draw() const;

    inline int getX() const { return x; }
    inline int getY() const { return y; }
    inline int getWidth() const { return rect.w; }
    inline int getHeight() const { return rect.h; }

    inline SDL_FRect getRect() const { return rect; }
    inline void setRect(SDL_FRect rect) { std::swap(this->rect, rect); }
    inline bool collide(GameBlock &other) {
        return SDL_HasRectIntersectionFloat(&rect, &other.rect);
    }

private:
    int x, y;
    SDL_Renderer *renderer;
    Color color;
    SDL_FRect rect;
};

#endif
