#include"commonLibs.h"

class camera {
    public:
    camera(vec3 position = vec3(0, 0, 0), vec3 direction = vec3(0, 1, 0)) {
        this->position = position;
        this->direction = direction.normalize();
    }

    dot3 convertToCamera(dot3 dot) { // Преобразование координат точки в координаты относительно камеры
        std::vector<double> cords {dot.getCords()};
        std::vector<double> camCords {this->position.getCords()};
        return dot3(cords[0] - camCords[0], cords[1] - camCords[1], cords[2] - camCords[2]);
        // добавить преобразование поворота (возможно ввести базис камеры)
    }

    friend std::ostream& operator<<(std::ostream& stream, camera cam);

    private:
    vec3 position;
    vec3 direction;
};


std::ostream& operator<<(std::ostream& stream, camera cam) {
    stream << "(Position:" << cam.position << ')' << std::endl;
    stream << "(Direction:" << cam.direction << ')' << std::endl;
    return stream;
}