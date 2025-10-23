#pragma once

#include"vec3.h"

// class vec3;


class matrix3 {
public:
    
    vec3 xVec;
    vec3 yVec;
    vec3 zVec;
    
    matrix3 (vec3 vector1, vec3 vector2, vec3 vector3);

    vec3 operator*(vec3 v);

};