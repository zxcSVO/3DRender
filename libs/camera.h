#pragma once

#include"commonLibs.h"
#include"vec3.h"
#include"matrix3.h"


class camera {
    public:

    vec3 position;
    //Направление взгляда камеры лежит в basis.yVec
    matrix3 basis{vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1)};

    camera(vec3 position = vec3(0, 0, 0));
    camera(double x, double y, double z);

    //Преобразование глобальных координат в относительные координаты камеры
    vec3 convertToCamera(vec3 dot);
    //Преобразование глобальных координат в относительные координаты камеры
    polygon convertToCamera(polygon pol);
    vec3 getDirection();
    bool isDraw(polygon pol);

};


std::ostream& operator<<(std::ostream& stream, camera cam);