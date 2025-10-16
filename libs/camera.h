#include"commonLibs.h"

class camera {
    public:

    vec3 position;
    //Направление всгляда камеры лежит в basis.yVec
    matrix3 basis{vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1)};

    camera(vec3 position = vec3(0, 0, 0)) {
        this->position = position;
    }

    dot3 convertToCamera(vec3 dot) { // Преобразование координат точки в координаты относительно камеры
        std::vector<double> cords {dot.getCords()};
        std::vector<double> camCords {this->position.getCords()};
        return dot3(cords[0] - camCords[0], cords[1] - camCords[1], cords[2] - camCords[2]);
        // добавить преобразование поворота (возможно ввести базис камеры)
    }
    vec3 getDirection() {
        return this->basis.yVec;
    }

    friend std::ostream& operator<<(std::ostream& stream, camera cam);

};


std::ostream& operator<<(std::ostream& stream, camera cam) {
    stream << "(Position:" << cam.position << ')' << std::endl;
    // stream << "(Direction:" << cam.yDirection << ')' << std::endl;
    return stream;
}