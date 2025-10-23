#pragma once

#include"commonLibs.h"
#include"polygon.h"
// #include"vec3.h"

//это какаято пиздища


polygon::polygon(vec3 d11, vec3 d12, vec3 d13) {
    this->d1 = d11;
    this->d2 = d12;
    this->d3 = d13;
}

vec3 polygon::normal() {
    return (-vectorMult(this->d2 - this->d1, this->d3 - this->d1)).normalize();   
}

// bool polygon::isDraw(camera cam) {
//     return scalarMult(this->normal(), cam.basis.yVec) < 0;
// }


std::ostream& operator<<(std::ostream& stream, polygon pol) {
    stream << '(' << pol.d1.x << ' ' << pol.d1.y << ' ' << pol.d1.z << ')' << std::endl;
    stream << '(' << pol.d2.x << ' ' << pol.d2.y << ' ' << pol.d2.z << ')' << std::endl;
    stream << '(' << pol.d3.x << ' ' << pol.d3.y << ' ' << pol.d3.z << ')' << std::endl;
    return stream;
}