#pragma once

#include"camera.h"


camera::camera(vec3 position) {
    this->position = position;
}

camera::camera(double x, double y, double z) {
    this->position = vec3(x, y, z);
}

vec3 camera::convertToCamera(vec3 dot) {
    return this->basis * vec3(dot.x - this->position.x, dot.y - this->position.y, dot.z - this->position.z);
}

polygon camera::convertToCamera(polygon pol) {
    return polygon(this->convertToCamera(pol.d1), this->convertToCamera(pol.d2), this->convertToCamera(pol.d3));
}

vec3 camera::getDirection() {
    return this->basis.yVec;
}
bool camera::isDraw(polygon pol) {
    return scalarMult(pol.normal(), this->basis.yVec) < 0;
}


std::ostream& operator<<(std::ostream& stream, camera cam) {
    stream << "(Position: " << cam.position << ')' << std::endl;
    stream << "(Direction: " << cam.basis.yVec << ')' << std::endl;
    return stream;
}