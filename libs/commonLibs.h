#pragma once

// classes
class vec3;
class dot3;
class matrix3;
class camera;
class polygon;
class model;

vec3 polygon::d1, polygon::d2, polygon::d3;
// void polygon::polygon(vec3 d1, vec3 d2, vec3 d3)

//Переписать все так как сказал дима


//buildin libs
#include<cmath>
#include<vector>
#include<iostream>
#include<math.h>

//my libs
#include"vec3.h"
#include"dot3.h"
#include"matrix3.h"
#include"camera.h"
#include"polygon.h"
#include"model.h"
#include"transformations.h"

//defines
#define M_PI 3.1415