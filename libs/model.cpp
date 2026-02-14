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
std::vector<polygon> model::toDraw(camera cam, bool carcas = false) {
    std::vector<polygon> toDraw;
    for (polygon pol:polygons) {
        if ((carcas || cam.isDraw(pol))) {
            for (auto clippedPol:cam.fullClip(cam.convertToCamera(this->convertToGlobal(pol)))) {
                toDraw.push_back(clippedPol);
            }
        }
    }
    return toDraw;
}

void model::rotateXY(float angle) {
    matrix3 mt = getRotationMatrixXY(angle);
    for (auto& pol:this->polygons) {
        pol = pol * mt;
    }
}

void model::rotateYZ(float angle) {
    matrix3 mt = getRotationMatrixYZ(angle);
    for (auto& pol:this->polygons) {
        pol = pol * mt;
    }
}

void model::rotateXZ(float angle) {
    matrix3 mt = getRotationMatrixXZ(angle);
    for (auto& pol:this->polygons) {
        pol = pol * mt;
    }
}

