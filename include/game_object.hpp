#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

class GameObject {
public:
    virtual void update() = 0;
    virtual void draw() const = 0;
};

#endif
