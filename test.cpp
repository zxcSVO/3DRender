#include "libs/cppLibs.h"

int main() {
    polygon test{vec3(0, 1, -1), vec3(0, 1, 1), vec3(0, -1, 0)};
    std::vector<polygon> res = test.clip(vec3(0, 1, 0), vec3(0, 0, 0));
    std::cout << res.size() << std::endl << res[0] << std::endl << std::endl << res[1];
    while (1){}
    return 0;
}