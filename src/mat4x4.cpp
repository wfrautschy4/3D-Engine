#include "mat4x4.h"


// Constructor
mat4x4::mat4x4(){
        m[0][0] = 0; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
        m[1][0] = 0; m[1][1] = 0; m[1][2] = 0; m[1][3] = 0;
        m[2][0] = 0; m[2][1] = 0; m[2][2] = 0; m[2][3] = 0;
        m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 0;
    }

mat4x4::mat4x4(float m11, float m12, float m13, float m14,
        float m21, float m22, float m23, float m24,
        float m31, float m32, float m33, float m34,
        float m41, float m42, float m43, float m44) {
    m[0][0] = m11; m[0][1] = m12; m[0][2] = m13; m[0][3] = m14;
    m[1][0] = m21; m[1][1] = m22; m[1][2] = m23; m[1][3] = m24;
    m[2][0] = m31; m[2][1] = m32; m[2][2] = m33; m[2][3] = m34;
    m[3][0] = m41; m[3][1] = m42; m[3][2] = m43; m[3][3] = m44;
}

// Operator overloading
const mat4x4 mat4x4::operator*(const mat4x4 &other) {
    mat4x4 mat{};
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            for(int k = 0; k < 4; k++){
                mat.m[r][c] += this->m[r][k] * other.m[k][c];
            }
        }
    }
    return mat;
}

const vec3 mat4x4::operator*(const vec3 &v) {
    vec3 vec{};
    for(int r = 0; r < 4; r++){
        vec.x = this->m[r][0] * v.x + this->m[r][1] * v.y + this->m[r][2] * v.z + this->m[r][3] * v.h;
        vec.y = this->m[r][0] * v.x + this->m[r][1] * v.y + this->m[r][2] * v.z + this->m[r][3] * v.h;
        vec.z = this->m[r][0] * v.x + this->m[r][1] * v.y + this->m[r][2] * v.z + this->m[r][3] * v.h;
        vec.h = this->m[r][0] * v.x + this->m[r][1] * v.y + this->m[r][2] * v.z + this->m[r][3] * v.h;
    }
    return vec;
}


const mat4x4 mat4x4::operator*(float scalar){ 
    mat4x4 mat{};
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            mat.m[r][c] = this->m[r][c] * scalar;
        }
    }
    return mat;
}

const mat4x4 mat4x4::operator+(const mat4x4 &other) {
    mat4x4 mat{};
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            mat.m[r][c] = this->m[r][c] + other.m[r][c];
        }
    }
    return mat;
}

const mat4x4 mat4x4::operator-(const mat4x4 &other) {
    mat4x4 mat{};
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            mat.m[r][c] = this->m[r][c] - other.m[r][c];
        }
    }
    return mat;
}

const mat4x4 mat4x4::operator/(float scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero is not allowed.");
    }
    mat4x4 mat{};
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            mat.m[r][c] = this->m[r][c] / scalar;
        }
    }
    return mat;
}



// Matrix Operations
mat4x4 mat4x4::transpose() const {
    mat4x4 mat{};
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            mat.m[c][r] = this->m[r][c];
        }
    }
    return mat;
}

mat4x4 mat4x4::inverse() const {
    // Placeholder for inverse calculation
    // In a real implementation, you would calculate the inverse of the matrix
    // This is a complex operation and typically requires additional libraries or algorithms
    throw std::runtime_error("Inverse calculation not implemented.");
}

float mat4x4::determinant() const {
    // Placeholder for determinant calculation
    // In a real implementation, you would calculate the determinant of the matrix
    // This is a complex operation and typically requires additional libraries or algorithms
    throw std::runtime_error("Determinant calculation not implemented.");
}



// Helper
static mat4x4 Identity() {
    return mat4x4(1, 0, 0, 0,
                  0, 1, 0, 0,
                  0, 0, 1, 0,
                  0, 0, 0, 1);
};


// ToString
std::ostream& operator<<(std::ostream& os, const mat4x4 &m) {
    os << "[" << m.m[0][0] << ", " << m.m[0][1] << ", " << m.m[0][2] << ", " << m.m[0][3] << "]\n"
       << "[" << m.m[1][0] << ", " << m.m[1][1] << ", " << m.m[1][2] << ", " << m.m[1][3] << "]\n"
       << "[" << m.m[2][0] << ", " << m.m[2][1] << ", " << m.m[2][2] << ", " << m.m[2][3] << "]\n"
       << "[" << m.m[3][0] << ", " << m.m[3][1] << ", " << m.m[3][2] << ", " << m.m[3][3] << "]\n";
    return os;
}