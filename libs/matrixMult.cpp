#pragma once

#include"matrixMult.h"

vec3 operator*(vec3 v, matrix3 mt) {
    return vec3(v.x * mt.xVec.x + v.y * mt.yVec.x + v.z * mt.zVec.x,
                v.x * mt.xVec.y + v.y * mt.yVec.y + v.z * mt.zVec.y,
                v.x * mt.xVec.z + v.y * mt.yVec.z + v.z * mt.zVec.z);
}

polygon operator*(polygon pol, matrix3 mt) {
    return polygon(pol.d1 * mt, pol.d2 * mt, pol.d3 * mt);
}

matrix3 operator*(matrix3 mt1, matrix3 mt2) {
    return matrix3(mt1.xVec * mt2, mt1.yVec * mt2, mt1.zVec * mt2);
}