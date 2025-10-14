#include"commonLibs.h"


// Переписать все точки на вектора


class dot3 {
    public:
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
        std::vector<double> cords = vector.getCords();
        return dot3(this->x + cords[0], this->y + cords[1], this->z + cords[2]);
    }
    dot3 operator-(vec3 vector) {
        std::vector<double> cords = vector.getCords();
        return dot3(this->x - cords[0], this->y - cords[1], this->z - cords[2]);
    }
    void operator+=(vec3 vector) {
        std::vector<double> cords = vector.getCords();
        this->x = this->x + cords[0];
        this->y = this->y + cords[1];
        this->z = this->z + cords[2];
    }
    void operator-=(vec3 vector) {
        std::vector<double> cords = vector.getCords();
        this->x = this->x - cords[0];
        this->y = this->y - cords[1];
        this->z = this->z - cords[2];
    }
    
    std::vector<double> getCords() {
        std::vector<double> cords;
        cords.push_back(this->x);
        cords.push_back(this->y);
        cords.push_back(this->z);
        return cords;
    }

    friend std::ostream& operator<<(std::ostream& stream, dot3 dot);
    friend double dist(dot3 dot_1, dot3 dot_2);
    friend vec3 toVector(dot3 start, dot3 end);

    private:
    double x, y, z;
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