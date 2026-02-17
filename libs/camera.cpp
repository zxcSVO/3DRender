#pragma once

#include"camera.h"
#include"matrixMult.h"


camera::camera(vec3 position, float fovX, float fovY) {
    this->position = position;
    this->fovX = fovX;
    this->fovY = fovY;
}

vec3 camera::convertToCamera(vec3 dot) {
    return vec3(dot.x - this->position.x, dot.y - this->position.y, dot.z - this->position.z) * this->basis.transpose();
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
    this->rotateX(-this->xAngle, false);
    matrix3 mt = getRotationMatrixYZ(angle);
    if (this->yAngle + angle > M_PI / 2) {
        this->yAngle = M_PI / 2;
    } else if (this->yAngle + angle < -M_PI / 2) {
        this->yAngle = -M_PI / 2;
    } else {
        this->basis = this->basis * mt;
        this->yAngle += angle;
    }
    this->rotateX(this->xAngle, false);
}

void camera::rotateX(float angle, bool basic) {
    if (basic) {
        this->xAngle += angle;
    }
    matrix3 mt = getRotationMatrixXY(angle);
    this->basis = this->basis * mt;
}

void camera::rotate(float angleX, float angleY) {
    this->basis = matrix3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
    this->xAngle += angleX;
    this->yAngle += angleY;
    matrix3 rtX = getRotationMatrixXY(this->xAngle), rtY = getRotationMatrixYZ(this->yAngle);
    this->basis = this->basis * rtY;
    this->basis = this->basis * rtX;
    // std::cout << this->basis.xVec << std::endl;
    // std::cout << this->basis.yVec << std::endl;
    // std::cout << this->basis.zVec << std::endl << std::endl;
}

std::vector<float> camera::projection(vec3 v) {
    std::vector<float> res;
    res.push_back(v.x / v.y * cos(this->fovX / 2) / sin(this->fovX / 2) * xRes / 2 + xRes / 2);
    res.push_back(v.z / v.y * cos(this->fovY / 2) / sin(this->fovY / 2) * yRes / 2 + yRes / 2);
    // std::cout << this->fovX << std::endl << this->fovY << std::endl << atan(static_cast<double>(yRes) / xRes * tan(this->fovX / 2)) << std::endl << std::endl;
    return res;
}

std::vector<polygon> camera::fullClip(polygon pol) {
    std::vector<polygon> res, res2;
    res = pol.clip(vec3(-cos(this->fovX / 2), sin(this->fovX / 2), 0), vec3(0, 0, 0));
    res2.clear();
    for (auto el:res) {
        for(auto el2:el.clip(vec3(cos(this->fovX / 2), sin(this->fovX / 2), 0), vec3(0, 0, 0))) res2.push_back(el2); 
    }
    res = res2;
    res2.clear();
    for (auto el:res) {
        for(auto el2:el.clip(vec3(0, sin(this->fovY / 2), cos(this->fovY / 2)), vec3(0, 0, 0))) res2.push_back(el2); 
    }
    res = res2;
    res2.clear();
    for (auto el:res) {
        for(auto el2:el.clip(vec3(0, sin(this->fovY / 2), -cos(this->fovY / 2)), vec3(0, 0, 0))) res2.push_back(el2); 
    }
    res = res2;
    return res;
}

std::ostream& operator<<(std::ostream& stream, camera cam) {
    stream << "(Position: " << cam.position << ')' << std::endl;
    stream << "(Direction: " << cam.basis.yVec << ')' << std::endl;
    return stream;
}