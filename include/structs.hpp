#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include "vec2.hpp"
#include <SDL3/SDL.h>
#include <bitset>
#include <cstdint>
#include <memory>
#include <set>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

using Component = std::uint8_t;
const Component MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>;

class System {
public:
    std::set<int> entities;
};

struct Transform {
    Vec2 position;
};
struct RigidBody {
    Vec2 velocity;
    Vec2 acceleration;
};

#endif
