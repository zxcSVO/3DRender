#include"commonLibs.h"


// Переписать все точки на вектора


class dot3 {
    public:
    
    double x, y, z;
    
    dot3(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    dot3() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    dot3 operator+(vec3 vector) {
        return dot3(this->x + vector.x, this->y + vector.y, this->z + vector.z);
    }
    dot3 operator-(vec3 vector) {
        return dot3(this->x - vector.x, this->y - vector.y, this->z - vector.z);
    }
    void operator+=(vec3 vector) {
        this->x = this->x + vector.x;
        this->y = this->y + vector.y;
        this->z = this->z + vector.z;
    }
    void operator-=(vec3 vector) {
        this->x = this->x - vector.x;
        this->y = this->y - vector.y;
        this->z = this->z - vector.z;
    }
    
    std::vector<double> getCords() {
        std::vector<double> cords;
        cords.push_back(this->x);
        cords.push_back(this->y);
        cords.push_back(this->z);
        return cords;
    }

};

std::ostream& operator<<(std::ostream& stream, dot3 dot) {
    stream << dot.x << ' ' << dot.y << ' ' << dot.z;
    return stream;
}

double dist(dot3 dot_1, dot3 dot_2) {
    return sqrt(pow((dot_1.x - dot_2.x), 2) + pow((dot_1.y - dot_2.y), 2));
}

vec3 toVector(dot3 start, dot3 end) {
    return vec3(end.x - start.x, end.y - start.y, end.z - start.z);
}