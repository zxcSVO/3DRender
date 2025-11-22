#pragma once

#include"camera.h"
#include"matrixMult.h"


camera::camera(vec3 position) {
    this->position = position;
}

camera::camera(float x, float y, float z) {
    this->position = vec3(x, y, z);
}

vec3 camera::convertToCamera(vec3 dot) {
    return vec3(dot.x - this->position.x, dot.y - this->position.y, dot.z - this->position.z) * this->basis;
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

void camera::rotateY(float angle) {
    rotateX(0);
}

void camera::rotateX(float angle) {
    rotateY(0);
}

std::vector<float> camera::projection(vec3 v) {
    std::vector<float> res;
    res.push_back(v.x / v.y * cos(M_PI / 3) / sin(M_PI / 3) * 960 + 960);
    res.push_back(v.z / v.y * cos(atan(static_cast<double>(1200) / 1920 * tan(M_PI / 3))) / sin(atan(static_cast<double>(1200) / 1920 * tan(M_PI / 3))) * 600 + 600);
    // res.push_back(v.x * 120 / v.y + 960);
    // res.push_back(v.z * 120 / v.y + 600);
    return res;
}

std::ostream& operator<<(std::ostream& stream, camera cam) {
    stream << "(Position: " << cam.position << ')' << std::endl;
    stream << "(Direction: " << cam.basis.yVec << ')' << std::endl;
    return stream;
}