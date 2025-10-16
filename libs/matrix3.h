#include"commonLibs.h"
#include<iostream>

class matrix3 {
    public:
    
    vec3 xVec;
    vec3 yVec;
    vec3 zVec;
    
    matrix3 (vec3 vector1, vec3 vector2, vec3 vector3) {
        this->xVec = vector1;
        this->yVec = vector2;
        this->zVec = vector3;
    }
    vec3 operator*(vec3 v){
        // std::cout << v.x * this->xVec.x << ' ' << v.y * this->yVec.x * v.z * this->zVec.x << std::endl;
        return vec3(v.x * this->xVec.x + v.y * this->yVec.x + v.z * this->zVec.x,
                    v.x * this->xVec.y + v.y * this->yVec.y + v.z * this->zVec.y,
                    v.x * this->xVec.z + v.y * this->yVec.z + v.z * this->zVec.z);
    }

};