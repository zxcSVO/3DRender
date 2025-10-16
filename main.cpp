#include"libs/commonLibs.h"

int main() {

    camera cam;
    matrix3 mt{vec3(2, -2, -1), vec3(4, 1, 0), vec3(0, 3, 1)};
    vec3 v{1, 2, -1};
    std::cout << mt.xVec << std::endl;
    std::cout << mt * v;
    return 0;
}
// vec3 operator*(vec3 v){
//     return vec3(v.x * this->xVec.x + v.y * this->yVec.x * v.z * this->zVec.x,
//                 v.x * this->xVec.y + v.y * this->yVec.y * v.z * this->zVec.y,
//                 v.x * this->xVec.z + v.y * this->yVec.z * v.z * this->zVec.z);
// }
// 2 -2 -1 xVec
// 4  1  0 yVec
// 0  3  1 zVec