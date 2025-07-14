#include <iostream>

#ifndef VEC3_H
#define VEC3_H

class vec3 {
    public: 

    // Properties
    float x, y, z;
    float h = 1.0f; // Homogeneous coordinate, default to 1.0 for 3D vectors

    // Constructor
    vec3();
    vec3(float x, float y, float z);

    // Operator overloading
    vec3 operator+(vec3 &v);
    vec3 operator-(vec3 &v);
    vec3 operator*(float scalar);
    friend vec3 operator*(const float scalar, const vec3 &v);
    vec3 operator/(float scalar);
    
    // Vector Operations
    float dot(const vec3 v);
    vec3 cross(const vec3 v);

    // ToString
    friend std::ostream& operator<<(std::ostream& os, const vec3& v);


};

#endif