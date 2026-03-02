#pragma once

#include"helpFuncs.h"

vec3 interrsectPlaneLine(const vec3& planeDot, const vec3& planeNormal, const vec3& lineStart, const vec3& lineEnd) {
    vec3 planeNormalized = planeNormal.normalize();
    float planeD = -scalarMult(planeNormalized, planeDot);
    float ad = scalarMult(planeNormalized, lineStart);
    float bd = scalarMult(planeNormalized, lineEnd);
    float t = (-planeD - ad) / (bd - ad);
    vec3 vecStartToEnd = lineEnd - lineStart;
    vec3 vecIntersect = vecStartToEnd * t;
    return lineStart + vecIntersect;
}

float dist(const vec3& planeNormal, const vec3& planePoint, const vec3& point){
    vec3 planeNormalized = planeNormal.normalize();
    return scalarMult(planeNormalized, point - planePoint);
}