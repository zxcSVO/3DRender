#pragma once

#include"commonLibs.h"
#include"vec3.h"
#include"matrix3.h"
#include"polygon.h"


class camera {
    public:

    vec3 position;
    //Направление взгляда камеры лежит в basis.yVec
    matrix3 basis{vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1)};
    float xAngle = 0, yAngle = 0;
    float fovX, fovY;

    camera(vec3 position = vec3(0, 0, 0), float fovX = M_PI * 2 / 3, float fovY = 2 * atan(static_cast<double>(yRes) / xRes * tan(M_PI / 3)));

    //Преобразование глобальных координат в относительные координаты камеры
    vec3 convertToCamera(vec3 dot);
    vec3 convertToCameraRotation(vec3 dot);
    //Преобразование глобальных координат в относительные координаты камеры
    polygon convertToCamera(polygon pol);
    vec3 getDirection();
    bool isDraw(polygon pol);
    void rotateY(float angle);
    void rotateX(float angle, bool basic = true);
    void rotate(float angleX, float angleY);
    std::vector<float> projection(vec3 v);
    std::vector<polygon> fullClip(polygon pol);

};


std::ostream& operator<<(std::ostream& stream, camera cam);