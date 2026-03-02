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
    
    matrix3 (vec3, vec3, vec3);

    matrix3 transpose() const;
    float determ() const;
    matrix3 invert() const;

};


matrix3 getRotationMatrixXY(const float&);
matrix3 getRotationMatrixYZ(const float&);
matrix3 getRotationMatrixXZ(const float&);