#pragma once

#include"commonLibs.h"
#include"vec3.h"
#include"polygon.h"
#include"camera.h"
#include"matrixMult.h"


class model {
    public: 
    
    std::vector<polygon> polygons;
    vec3 origin;

    model(vec3, std::vector<polygon>&);
    

    vec3 convertToGlobal(vec3&) const;

    polygon convertToGlobal(polygon&) const;

    //Возвращает массив полигонов для отрисовки, координаты относительно камеры
    std::vector<polygon> toDraw(camera&, bool) const;

    void rotateXY(const float&);
    void rotateYZ(const float&);
    void rotateXZ(const float&);

//добавить преобрзовани всех точек и полигонов в глобальные кординаты и обратно.

};