#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "game_object.hpp"
#include "structs.hpp"
#include <SDL3/SDL.h>
#include <utility>

class Block : public GameObject {
public:
    Block(int x, int y, int width, int height, Color color,
          SDL_Renderer *renderer)
        : x(x), y(y), color(color), renderer(renderer),
          rect(x, y, width, height) {}

    virtual void update() {}

    inline void draw() const {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &rect);
    }

    inline int getX() const { return x; }
    inline int getY() const { return y; }
    inline int getWidth() const { return rect.w; }
    inline int getHeight() const { return rect.h; }

    inline SDL_FRect getRect() const { return rect; }
    inline void setRect(SDL_FRect rect) { std::swap(this->rect, rect); }
    inline bool collide(Block &other) {
        return SDL_HasRectIntersectionFloat(&rect, &other.rect);
    }

private:
    int x, y;
    SDL_Renderer *renderer;
    Color color;
    SDL_FRect rect;
};

#endif
