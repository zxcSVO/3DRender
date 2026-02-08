#pragma once

#include"commonLibs.h"
#include"vec3.h"

vec3 interrsectPlaneLine(vec3 planeDot, vec3 planeNormal, vec3 lineStart, vec3 lineEnd, float& t);
float dist(vec3 planeNormal, vec3 planePoint, vec3 point);

