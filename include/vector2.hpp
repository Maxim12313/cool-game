#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>

class Vector2 {
public:
    float x, y;
    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2 operator+(const Vector2 &other) const {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator-(const Vector2 &other) const {
        return Vector2(x - other.x, y - other.y);
    }
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    float magnitude() const { return std::sqrt(x * x + y * y); }

    Vector2 normalized() const {
        float val = magnitude();
        return val == 0 ? Vector2() : Vector2(x / val, y / val);
    }
};

#endif
