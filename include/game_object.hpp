#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "vector2.hpp"

class GameObject {
public:
    GameObject(int x, int y) : pos(x, y) {}
    virtual void update() {}
    virtual void draw(int offX, int offY) const = 0;
    virtual ~GameObject() {}

public:
    Vector2 pos;
};

#endif
