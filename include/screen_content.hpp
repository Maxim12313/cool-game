#ifndef COLLISION_HANDLER_HPP
#define COLLISION_HANDLER_HPP

#include "chunk.hpp"
#include "game_object.hpp"
#include "vector2.hpp"
#include <functional>

class ScreenContent : public GameObject {
public:
    ScreenContent(int x, int y) : GameObject(x, y) {}

    void update() {
        for (Chunk *chunk : chunks) {
            chunk->update();
        }
    }

    void draw(int offX, int offY) const {
        for (Chunk *chunk : chunks) {
            chunk->draw(offX, offY);
        }
    }

    void addChunk(Chunk *chunk) { chunks.push_back(chunk); }
    void removeChunk(Chunk *chunk) {
        auto it = std::find(begin(chunks), end(chunks), chunk);
        if (it == end(chunks))
            return;
        chunks.erase(it);
    }

    // invariant: pos not intersecting
    // Vector2 adjustedPlayerMovement(Vector2 pos, Vector2 change,
    //                                std::function<int(int, int)> &funcX,
    //                                std::function<int(int, int)> &funcY) {}

    ~ScreenContent() {
        for (Chunk *chunk : chunks)
            delete chunk;
    }

private:
    std::vector<Chunk *> chunks;
};

#endif
