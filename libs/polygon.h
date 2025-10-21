#include "commonLibs.h"

class polygon {
    public:
    
    static vec3 d1, d2, d3;
    
    polygon(vec3 d1, vec3 d2, vec3 d3) {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
    }
    
    vec3 normal() {
        return (-vectorMult(this->d2 - this->d1, this->d3 - this->d1)).normalize();   
    }

    bool isDraw(camera cam) {
        return scalarMult(this->normal(), cam.basis.yVec) < 0;
    }

    friend std::ostream& operator<<(std::ostream& stream, polygon pol);

};

std::ostream& operator<<(std::ostream& stream, polygon pol) {
    stream << '(' << pol.d1.x << ' ' << pol.d1.y << ' ' << pol.d1.z << ')' << std::endl;
    stream << '(' << pol.d2.x << ' ' << pol.d2.y << ' ' << pol.d2.z << ')' << std::endl;
    stream << '(' << pol.d3.x << ' ' << pol.d3.y << ' ' << pol.d3.z << ')' << std::endl;
    return stream;
}