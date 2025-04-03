#ifndef VEC_HPP
#define VEC_HPP

#include <cmath>

class Vec2 {
public:
    float x, y;

    Vec2() : x(0), y(0) {}
    Vec2(float x, float y) : x(x), y(y) {}
    Vec2 operator+(Vec2 &other) const { return Vec2(x + other.x, y + other.y); }
    Vec2 operator*(float scalar) const { return Vec2(x * scalar, y * scalar); }
    float magnitude() const { return std::sqrt(x * x + y * y); }
};

#endif
