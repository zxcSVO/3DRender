#pragma once

#include"matrix3.h"


matrix3::matrix3 (vec3 vector1, vec3 vector2, vec3 vector3) {
    this->xVec = vector1;
    this->yVec = vector2;
    this->zVec = vector3;
}

matrix3 matrix3::transpose() {
    return matrix3(vec3(this->xVec.x, this->yVec.x, this->zVec.x), 
                   vec3(this->xVec.y, this->yVec.y, this->zVec.y), 
                   vec3(this->xVec.z, this->yVec.z, this->zVec.z));
}

float matrix3::determ() {
    return this->xVec.x * this->yVec.y * this->zVec.z + this->xVec.y * this->yVec.z * this->zVec.x + this->xVec.z * this->yVec.x * this->zVec.y - this->xVec.z * this->yVec.y * this->zVec.x - this->xVec.y * this->yVec.x * this->zVec.z - this->xVec.x * this->yVec.z * this->zVec.y;
}
//Не ортнормированно и я не уверен что вобще работает
matrix3 matrix3::invert() {
    float det = this->determ();
    return matrix3{this->xVec / det, this->yVec / det, this->zVec / det};
}

matrix3 getRotationMatrixXY(float angle) {
    matrix3 mt{vec3(cos(angle), sin(angle), 0), 
               vec3(-sin(angle), cos(angle), 0),
               vec3(0, 0, 1)};
    return mt;
}

matrix3 getRotationMatrixYZ(float angle) {
    matrix3 mt{vec3(1, 0, 0), 
               vec3(0, cos(angle), sin(angle)),
               vec3(0, -sin(angle), cos(angle))};
    return mt;
}

matrix3 getRotationMatrixXZ(float angle) {
    matrix3 mt{vec3(cos(angle), 0, -sin(angle)), 
               vec3(0, 1, 0),
               vec3(sin(angle), 0, cos(angle))};
    return mt;
}