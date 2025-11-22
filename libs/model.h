#pragma once

#include"commonLibs.h"
#include"vec3.h"
#include"polygon.h"
#include"camera.h"


class model {
    public: 
    
    std::vector<polygon> polygons;
    vec3 origin;

    model(vec3 origin, std::vector<polygon> polygons);
    

    vec3 convertToGlobal(vec3 dot);

    polygon convertToGlobal(polygon pol);

    //Возвращает массив полигонов для отрисовки, координаты относительно камеры
    std::vector<polygon> toDraw(camera cam, bool carcas);

    void rotateXY(float angle);
    void rotateYZ(float angle);
    void rotateXZ(float angle);

//добавить преобрзовани всех точек и полигонов в глобальные кординаты и обратно.

};