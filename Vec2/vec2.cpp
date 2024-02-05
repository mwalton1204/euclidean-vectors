#include "vec2.h"

Vec2::Vec2() : x(0.0f), y(0.0f) {}
Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator*(const Vec2& other) const {
    return Vec2(x * other.x, y * other.y);
}

Vec2 Vec2::operator/(float scalar) const {
    Vec2 scaledVec;
    if(scalar != 0) {
        scaledVec.x = x / scalar;
        scaledVec.y = y / scalar;
    }

    return scaledVec;
}

Vec2 Vec2::operator/(const Vec2& other) const {
    Vec2 scaledVec;
    if(other.x != 0 && other.y != 0) {
        scaledVec.x = x / other.x;
        scaledVec.y = y / other.y;
    }

    return scaledVec;
}

Vec2& Vec2::operator++() {
    x++;
    y++;

    return *this;
}

Vec2 Vec2::operator++(int) {
    Vec2 temp(*this);
    ++(*this);

    return temp;
}

Vec2& Vec2::operator--() {
    x--;
    y--;

    return *this;
}

Vec2 Vec2::operator--(int) {
    Vec2 temp(*this);
    --(*this);

    return temp;
}

Vec2& Vec2::operator+=(const Vec2& other) {
    x += other.x;
    y += other.y;

    return *this;
}

Vec2& Vec2::operator-=(const Vec2& other) {
    x -= other.x;
    y -= other.y;

    return *this;
}

Vec2& Vec2::operator*=(const float scalar) {
    x *= scalar;
    y *= scalar;

    return *this;
}

Vec2& Vec2::operator*=(const Vec2& other) {
    x *= other.x;
    y *= other.y;

    return *this;
}

Vec2& Vec2::operator/=(const float scalar) {
    if(scalar != 0) {
        x /= scalar;
        y /= scalar;
    }

    return *this;
}

Vec2& Vec2::operator/=(const Vec2& other) {
    if(other.x != 0 && other.y != 0) {
        x /= other.x;
        y /= other.y;
    }

    return *this;
}

Vec2& Vec2::operator=(const Vec2& other) {
    x = other.x;
    y = other.y;

    return *this;
}

bool Vec2::operator==(const Vec2& other) const {
    return x == other.x && y == other.y;
}

bool Vec2::operator!=(const Vec2& other) const {
    return x != other.x || y != other.y;
}

float Vec2::magnitude() const {
    return sqrt((x * x) + (y * y));
}

void Vec2::normalize() {
    float mag = magnitude();

    if(mag != 0) {
        x /= mag;
        y /= mag;
    }
}

float Vec2::dot(const Vec2& other) const {
    return (x * other.x) + (y * other.y);
}

float Vec2::angle(const Vec2& other) const {
    float absA = fabs(magnitude());
    float absB = fabs(other.magnitude());
    float angle;

    if(absA != 0 && absB != 0) {
    angle = acos(dot(other) / (absA * absB));
    }

    angle *= (180.0/M_PI);

    return angle;
}