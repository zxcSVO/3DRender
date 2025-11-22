#pragma once

#include"matrix3.h"


matrix3::matrix3 (vec3 vector1, vec3 vector2, vec3 vector3) {
    this->xVec = vector1;
    this->yVec = vector2;
    this->zVec = vector3;
}

// vec3 matrix3::operator*(vec3 v){
//     return vec3(v.x * this->xVec.x + v.y * this->yVec.x + v.z * this->zVec.x,
//                 v.x * this->xVec.y + v.y * this->yVec.y + v.z * this->zVec.y,
//                 v.x * this->xVec.z + v.y * this->yVec.z + v.z * this->zVec.z);
// }

// polygon matrix3::operator*(polygon pol){
//     return polygon(pol.d1 * *this, pol.d2 * *this, pol.d3 * *this);
// }

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