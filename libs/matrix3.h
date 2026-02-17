#pragma once

#include"commonLibs.h"
#include"vec3.h"
#include"polygon.h"

// класс матрицы, вектора распологаются по горизонтали
class matrix3 {
public:
    
    vec3 xVec;
    vec3 yVec;
    vec3 zVec;
    
    matrix3 (vec3 vector1, vec3 vector2, vec3 vector3);

    matrix3 transpose();
    float determ();
    matrix3 invert();

};


matrix3 getRotationMatrixXY(float angle);
matrix3 getRotationMatrixYZ(float angle);
matrix3 getRotationMatrixXZ(float angle);