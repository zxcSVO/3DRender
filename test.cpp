#include "libs/cppLibs.h"

int main() {
    // polygon test{vec3(0, 1, -1), vec3(0, 1, 1), vec3(0, -1, 0)};
    // std::vector<polygon> res = test.clip(vec3(0, 1, 0), vec3(0, 0, 0));
    // std::cout << res.size() << std::endl << res[0] << std::endl << std::endl << res[1];
    // std::cout << dist(vec3(0.84, 0.37, -0.38), vec3(0, 0, 0), vec3(6.09, -0.55, -5.4));
    // std::cout << 2 * atan(static_cast<double>(3) / 4 * tan(M_PI / 3));
    matrix3 test(vec3(4, 0, 0), vec3(0, 2, 0), vec3(0, 0, 3));
    std::cout << test.determ() << std::endl << std::endl;
    test = test.invert();
    std::cout << test.xVec << std::endl << test.yVec << std::endl << test.zVec << std::endl << std::endl;
    // test = test.transpose();
    // std::cout << test.xVec << std::endl << test.yVec << std::endl << test.zVec << std::endl << std::endl;
    while (1){}
    return 0;
}