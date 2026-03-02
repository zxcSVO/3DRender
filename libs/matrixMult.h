#pragma once

#include"commonLibs.h"
#include"matrix3.h"
#include"camera.h"
#include"vec3.h"
#include"polygon.h"

vec3 operator*(const vec3&, const matrix3&);
polygon operator*(const polygon&, const matrix3&);
matrix3 operator*(const matrix3&, const matrix3&);