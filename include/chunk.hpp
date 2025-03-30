#ifndef MAP_HPP
#define MAP_HPP
#include "config.hpp"
#include "game_object.hpp"
#include <SDL3/SDL_rect.h>
#include <tuple>
#include <vector>

class Chunk : public GameObject {
public:
    Chunk(int x, int y, int sideLength)
        : GameObject(x, y), sideLength(sideLength) {}

    void addBlock(GameObject *obj) { objects.push_back(obj); }
    void update() {
        for (GameObject *obj : objects) {
            obj->update();
        }
    }
    void draw(int offX, int offY) const {
        for (GameObject *obj : objects) {
            obj->draw(offX, offY);
        }
    }

    ~Chunk() {
        for (GameObject *obj : objects)
            delete obj;
    }

public:
    std::vector<GameObject *> objects;
    int sideLength;
};

#endif
