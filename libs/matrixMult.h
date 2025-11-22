#pragma once

#include"commonLibs.h"
#include"matrix3.h"
#include"camera.h"
#include"vec3.h"
#include"polygon.h"

vec3 operator*(vec3 v, matrix3 mt);
polygon operator*(polygon pol, matrix3 mt);
matrix3 operator*(matrix3 mt1, matrix3 mt2);