#pragma once

#include"polygon.h"


polygon::polygon(vec3 d11, vec3 d12, vec3 d13) {
    this->d1 = d11;
    this->d2 = d12;
    this->d3 = d13;
}

void polygon::invert() {
    vec3 tmp = this->d1;
    this->d1 = this->d2;
    this->d2 = tmp;
}

vec3 polygon::normal() {
    return (-vectorMult(this->d2 - this->d1, this->d3 - this->d1)).normalize();   
}


std::vector<polygon> polygon::clip(vec3 planeNormal, vec3 planePoint) {
    vec3 norm = this->normal();
    std::vector<polygon> result;
    std::vector<vec3> inside; int insideCount = 0;
    std::vector<vec3> outside; int outsideCount = 0;
    for (vec3 point:std::vector<vec3>{this->d1, this->d2, this->d3}) {
        if (dist(planeNormal, planePoint, point) > 0) {inside.push_back(point), insideCount++;}
        else {outside.push_back(point), outsideCount++;}
    }
    if (insideCount == 0) return std::vector<polygon>{};
    else if (insideCount == 1){
        polygon resPol{inside[0], interrsectPlaneLine(planePoint, planeNormal, inside[0], outside[0]), interrsectPlaneLine(planePoint, planeNormal, inside[0], outside[1])};
        if (resPol.normal() != norm) resPol.invert();
        return std::vector<polygon>{resPol};
    } else if (insideCount == 2){
        polygon resPol1{inside[0], inside[1], interrsectPlaneLine(planePoint, planeNormal, inside[0], outside[0])}, resPol2{inside[1], interrsectPlaneLine(planePoint, planeNormal, inside[0], outside[0]), interrsectPlaneLine(planePoint, planeNormal, inside[1], outside[0])};
        if (resPol1.normal() != norm) resPol1.invert();
        if (resPol2.normal() != norm) resPol2.invert();
        return std::vector<polygon>{resPol1, resPol2};
    } else {
        return std::vector<polygon>{*this};
    }
}

std::ostream& operator<<(std::ostream& stream, polygon pol) {
    stream << '(' << pol.d1.x << ' ' << pol.d1.y << ' ' << pol.d1.z << ')' << std::endl;
    stream << '(' << pol.d2.x << ' ' << pol.d2.y << ' ' << pol.d2.z << ')' << std::endl;
    stream << '(' << pol.d3.x << ' ' << pol.d3.y << ' ' << pol.d3.z << ')' << std::endl;
    return stream;
}