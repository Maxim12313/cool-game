#ifndef VEC_HPP
#define VEC_HPP

#include <cmath>
#include <strstream>

class Vec2 {
public:
    float x, y;

    Vec2() : x(0), y(0) {}
    Vec2(float xx, float yy) : x(xx), y(yy) {}
    Vec2 operator+(Vec2 &other) const { return Vec2(x + other.x, y + other.y); }
    Vec2 operator*(float scalar) const { return Vec2(x * scalar, y * scalar); }
    float magnitude() const { return std::sqrt(x * x + y * y); }
};

std::string to_string(Vec2 vec) {
    return std::to_string(vec.x) + " " + std::to_string(vec.y);
}

#endif
