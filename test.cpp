#include "libs/cppLibs.h"

int main() {
    matrix3 mt = getRotationMatrixXY(M_PI / 2);
    polygon pol{vec3(1, 0, 1), vec3(1, 0, -1), vec3(-1, 0, 1)};
    std::cout << pol << std::endl;
    pol = pol * mt;
    std::cout << pol << std::endl;
    while (1){}
    return 0;
}