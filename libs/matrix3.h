#pragma once

#include"commonLibs.h"
// #include"vec3.h"


class vec3;
// класс матрицы, вектора распологаются по горизонтали
class matrix3 {
public:
    
    vec3 *xVec;
    vec3 *yVec;
    vec3 *zVec;
    
    matrix3 (vec3 *vector1, vec3 *vector2, vec3 *vector3);


};


matrix3 getRotationMatrixXY(double angle);
matrix3 getRotationMatrixYZ(double angle);
matrix3 getRotationMatrixXZ(double angle);