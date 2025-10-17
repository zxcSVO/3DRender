#include"libs/commonLibs.h"

int main() {
    camera cam{vec3(2, 2, 0)};
    vec3 test{3, 3, 0};
    std::cout << cam.convertToCamera(test);
    
    return 0;
}
// добавить преобразование точек в базис камеры
