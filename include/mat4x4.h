#include "vec3.h"


class mat4x4 {
    public:

    // Properties
    float m[4][4];

    // Constructor
    mat4x4();
    mat4x4(float m11, float m12, float m13, float m14,
           float m21, float m22, float m23, float m24,
           float m31, float m32, float m33, float m34,
           float m41, float m42, float m43, float m44);

    // Operator overloading
    const mat4x4 operator*(const mat4x4 &other);
    const vec3 operator*(const vec3 &v);
    const mat4x4 operator*(float scalar);
    const mat4x4 operator+(const mat4x4 &other);
    const mat4x4 operator-(const mat4x4 &other);
    const mat4x4 operator/(float scalar);
  
    // Matrix Operations
    mat4x4 transpose() const;
    float determinant() const;
    mat4x4 inverse() const;

    // Helper
    static mat4x4 Identity();

    // ToString
    // friend std::ostream& operator<<(std::ostream& os, const mat4x4 &m);

};