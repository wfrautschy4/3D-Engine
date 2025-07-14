#include "vec3.h"


class mat4x4 {
    public:

    // Properties
    float m[4][4];



    // Constructor
    mat4x4(){
        m[0][0] = 0; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
        m[1][0] = 0; m[1][1] = 0; m[1][2] = 0; m[1][3] = 0;
        m[2][0] = 0; m[2][1] = 0; m[2][2] = 0; m[2][3] = 0;
        m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 0;
    }

    mat4x4(float m11, float m12, float m13, float m14,
           float m21, float m22, float m23, float m24,
           float m31, float m32, float m33, float m34,
           float m41, float m42, float m43, float m44) {
        m[0][0] = m11; m[0][1] = m12; m[0][2] = m13; m[0][3] = m14;
        m[1][0] = m21; m[1][1] = m22; m[1][2] = m23; m[1][3] = m24;
        m[2][0] = m31; m[2][1] = m32; m[2][2] = m33; m[2][3] = m34;
        m[3][0] = m41; m[3][1] = m42; m[3][2] = m43; m[3][3] = m44;
    }

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
    friend std::ostream& operator<<(std::ostream& os, const mat4x4 &m);

};