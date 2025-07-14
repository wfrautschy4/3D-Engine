// Author: Will Frautschy

#include <stdexcept>
#include <iostream>
#include <string>

#include "vec3.h"

// Constructor
vec3::vec3() : x(0), y(0), z(0) {}; // Default constructor initializes to (0, 0, 0)
vec3::vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
} 

// Operator overloading
vec3 vec3::operator+(vec3 &v) {
    return vec3(this->x + v.x, this->y + v.y, this->z + v.z);
}
vec3 vec3::operator-(vec3 &v) {
    return vec3(this->x - v.x, this->y - v.y, this->z - v.z);
}
vec3 vec3::operator*(float scalar) {
    return vec3(this->x * scalar, this->y * scalar, this->z * scalar);
}
vec3 operator*(const float scalar, const vec3 &v) {
    return vec3(v.x * scalar, v.y * scalar, v.z * scalar);
}
vec3 vec3::operator/(float scalar) {
    if (scalar != 0) {
        return vec3(this->x / scalar, this->y / scalar, this->z / scalar);
    } else {
        throw std::runtime_error("Division by zero is not allowed.");
    }
}

float vec3::dot(const vec3 v) {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

vec3 vec3::cross(const vec3 v) {
    return vec3(
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z,
        this->x * v.y - this->y * v.x
    );
}

// ToString
std::ostream& operator<<(std::ostream& os, const vec3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}