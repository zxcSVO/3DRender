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

    camera(vec3, float, float);

    //Преобразование глобальных координат в относительные координаты камеры
    vec3 convertToCamera(const vec3&);
    vec3 convertToCameraRotation(const vec3&);
    //Преобразование глобальных координат в относительные координаты камеры
    polygon convertToCamera(const polygon&);
    bool isDraw(const polygon&);
    void rotate(const float&, const float&);
    std::vector<float> projection(const vec3&);
    std::vector<polygon> fullClip(const polygon&);

};


std::ostream& operator<<(std::ostream&, camera);