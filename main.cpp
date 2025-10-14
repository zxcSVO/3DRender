#include"libs/commonLibs.h"

int main() {
    vec3 v1{0, 0, 0};
    vec3 v2{-1, 1, 0};
    vec3 v3{1, 1, 0};
    polygon p1 {v1, v2, v3};
    std::cout << p1.normal();
    return 0;
}