#include "commonLibs.h"

class polygon {
    public:
    polygon(vec3 d1, vec3 d2, vec3 d3) {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
    }
    vec3 normal() {
        return (-vectorMult(this->d2 - this->d1, this->d3 - this->d1)).normalize();
    }

    friend std::ostream& operator<<(std::ostream& stream, polygon pol);

    private:
    vec3 d1, d2, d3;
};

std::ostream& operator<<(std::ostream& stream, polygon pol) {
    std::vector<double> d1, d2, d3;
    d1 = pol.d1.getCords();
    d2 = pol.d2.getCords();
    d3 = pol.d3.getCords();
    stream << '(' << d1[0] << ' ' << d1[1] << ' ' << d1[2] << ')' << std::endl;
    stream << '(' << d2[0] << ' ' << d2[1] << ' ' << d2[2] << ')' << std::endl;
    stream << '(' << d3[0] << ' ' << d3[1] << ' ' << d3[2] << ')' << std::endl;
    return stream;
}