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
    std::cout << basic << ' ' << this->xAngle << std::endl;
    matrix3 mt = getRotationMatrixXY(angle);
    this->basis = this->basis * mt;
}
// void camera::rotateY(float angle, bool first) {
//     matrix3 mt = getRotationMatrixYZ(angle);
//     if (first) {
//         if (this->yAngle + angle > M_PI / 2) {
//             this->yAngle = M_PI / 2;
//         } else if (this->yAngle + angle < -M_PI / 2) {
//             this->yAngle = -M_PI / 2;
//         } else {
//             this->basis = this->basis * mt;
//             this->yAngle += angle;
//         }
//     }
// }

// void camera::rotateX(float angle) {
//     rotateY(-this->yAngle, false);
//     matrix3 mt = getRotationMatrixXY(angle);
//     this->basis = this->basis * mt;
//     rotateY(this->yAngle, false);
// }

std::vector<float> camera::projection(vec3 v) {
    std::vector<float> res;
    res.push_back(v.x / v.y * cos(fov / 2) / sin(fov / 2) * xRes / 2 + xRes / 2);
    res.push_back(v.z / v.y * cos(atan(static_cast<double>(yRes) / xRes * tan(fov / 2))) / sin(atan(static_cast<double>(yRes) / xRes * tan(fov / 2))) * yRes / 2 + yRes / 2);
    return res;
}

std::ostream& operator<<(std::ostream& stream, camera cam) {
    stream << "(Position: " << cam.position << ')' << std::endl;
    stream << "(Direction: " << cam.basis.yVec << ')' << std::endl;
    return stream;
}