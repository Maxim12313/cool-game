#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include "config.hpp"
#include <SDL3/SDL_rect.h>
#include <vector>

struct Color {
    int r, g, b, a;
};

struct Vector2 {
    float x, y;
    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2 operator+(const Vector2 &other) const {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    float magnitude() const { return std::sqrt(x * x + y * y); }
    Vector2 normalize() const {
        float mag = magnitude();
        return mag != 0 ? Vector2(x / mag, y / mag) : Vector2();
    }
};

struct Player {
    SDL_FRect rect;
    Color color;
    float sideLength;
    float speed;
    Player() {}
    Player(float sideLength, Color color, float speed)
        : sideLength(sideLength), color(color), speed(speed) {
        rect = SDL_FRect(Config::windowWidth / 2.0 - sideLength / 2,
                         Config::windowHeight / 2.0 - sideLength / 2,
                         sideLength, sideLength);
    }
};

struct GameRects {
    std::vector<SDL_FRect> rects;
    std::vector<Color> colors;
};

#endif
