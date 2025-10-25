#include"model.h"


model::model(vec3 origin, std::vector<polygon> polygons) {
    this->polygons = polygons;
    this->origin = origin;
}


vec3 model::convertToGlobal(vec3 dot) {
    return this->origin + dot;
}

polygon model::convertToGlobal(polygon pol) {
    return polygon(this->convertToGlobal(pol.d1), this->convertToGlobal(pol.d2), this->convertToGlobal(pol.d3));
}

//Возвращает массив полигонов для отрисовки, координаты относительно камеры
std::vector<polygon> model::toDraw(camera cam) {
    std::vector<polygon> toDraw;
    for (polygon pol:polygons) {
        if (pol.isDraw(cam)) {
            toDraw.push_back(cam.convertToCamera(this->convertToGlobal(pol)));
        }
    }
    return toDraw;
}

//добавить преобрзовани всех точек и полигонов в глобальные кординаты и обратно.
