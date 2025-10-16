#include"commonLibs.h"

class matrix3 {
    public:
    
    matrix3 (vec3 vector1, vec3 vector2, vec3 vector3) {
        this->xVec = vector1.normalize();
        this->yVec = vector2.normalize();
        this->zVec = vector3.normalize();
    }

    vec3 xVec;
    vec3 yVec;
    vec3 zVec;
};