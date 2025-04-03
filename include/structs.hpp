#ifndef STRUCTS_HPP
#define STRUCTS_HPP
#include "vec2.hpp"
#include <bitset>
#include <cstdint>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

using Component = std::uint8_t;
const Component MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>;

struct Transform {
    Vec2 position;
};

#endif
