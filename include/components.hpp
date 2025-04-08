#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include "vec2.hpp"

struct Transform {
    Vec2 position;
};

struct RigidBody {
    Vec2 velocity;
    Vec2 acceleration;
    float mass = 1;
};

#endif
