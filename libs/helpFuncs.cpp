#pragma once

#include"helpFuncs.h"

vec3 interrsectPlaneLine(vec3 planeDot, vec3 planeNormal, vec3 lineStart, vec3 lineEnd, float& t) {
    planeNormal = planeNormal.normalize();
    float planeD = -scalarMult(planeNormal, planeDot);
    float ad = scalarMult(planeNormal, lineStart);
    float bd = scalarMult(planeNormal, lineEnd);
    t = (-planeD - ad) / (bd - ad);
    vec3 vecStartToEnd = lineEnd - lineStart;
    vec3 vecIntersect = vecStartToEnd * t;
    return lineStart + vecIntersect; 
}

float dist(vec3 planeNormal, vec3 planePoint, vec3 point){
    planeNormal = planeNormal.normalize();
    return scalarMult(planeNormal, point - planePoint);
}