#ifndef MAP_HPP
#define MAP_HPP
#include "config.hpp"
#include "game_object.hpp"
#include <SDL3/SDL_rect.h>
#include <vector>

class Chunk : public GameObject {
public:
    Chunk(int x, int y) : rect(x, y, Config::chunkSize, Config::chunkSize) {}
    void addBlock(GameObject *obj) { objects.push_back(obj); }
    void update() {
        for (GameObject *obj : objects) {
            obj->update();
        }
    }
    void draw() const {
        for (GameObject *obj : objects) {
            obj->draw();
        }
    }
    ~Chunk() {
        for (GameObject *obj : objects)
            delete obj;
    }

private:
    SDL_FRect rect; // active area
    std::vector<GameObject *> objects;
};

#endif
