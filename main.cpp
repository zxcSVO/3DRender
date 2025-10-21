#include"libs/commonLibs.h"

int main() {
    polygon pol{vec3(1, 10, 0), vec3(1, 10, 1), vec3(2, 10, 0)};
    camera cam{};
    std::cout << pol.isDraw(cam);
    return 0;
}
// добавить преобразование точек в базис камеры
