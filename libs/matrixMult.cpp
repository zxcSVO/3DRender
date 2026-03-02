#pragma once

#include"matrixMult.h"

vec3 operator*(const vec3& v, const matrix3& mt) {
    return vec3(v.x * mt.xVec.x + v.y * mt.yVec.x + v.z * mt.zVec.x,
                v.x * mt.xVec.y + v.y * mt.yVec.y + v.z * mt.zVec.y,
                v.x * mt.xVec.z + v.y * mt.yVec.z + v.z * mt.zVec.z);
}

polygon operator*(const polygon& pol, const matrix3& mt) {
    return polygon(pol.d1 * mt, pol.d2 * mt, pol.d3 * mt, pol.color);
}

matrix3 operator*(const matrix3& mt1, const matrix3& mt2) {
    return matrix3(mt1.xVec * mt2, mt1.yVec * mt2, mt1.zVec * mt2);
}