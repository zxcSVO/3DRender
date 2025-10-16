#include"commonLibs.h"

class camera {
    public:

    vec3 position;
    //Направление взгляда камеры лежит в basis.yVec
    matrix3 basis{vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1)};

    camera(vec3 position = vec3(0, 0, 0)) {
        this->position = position;
    }
    
    camera(double x, double y, double z) {
        this->position = vec3(x, y, z);
    }

    vec3 convertToCamera(vec3 dot) { // Преобразование координат точки в координаты относительно камеры
        return this->basis * vec3(dot.x - this->position.x, dot.y - this->position.y, dot.z - this->position.z);
        // добавить преобразование поворота
    }
    vec3 getDirection() {
        return this->basis.yVec;
    }

    friend std::ostream& operator<<(std::ostream& stream, camera cam);

};


std::ostream& operator<<(std::ostream& stream, camera cam) {
    stream << "(Position: " << cam.position << ')' << std::endl;
    stream << "(Direction: " << cam.basis.yVec << ')' << std::endl;
    return stream;
}