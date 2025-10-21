#include"commonLibs.h"



class vec3 {
    public:
    double x, y, z;
        
    vec3(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    vec3(){
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    double lenth() {
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    bool operator==(const vec3 other_vector){
        return this->x - other_vector.x < 0.000001 && this->y - other_vector.y < 0.000001 && this->z - other_vector.z < 0.000001;
    }
    bool operator==(double len) {
        return this->lenth() - len < 0.000001;
    }

    vec3 operator/(double coef) {
        return vec3(this->x / coef, this->y / coef, this->z / coef);
    }

    vec3 operator*(double coef) {
        return vec3(this->x * coef, this->y * coef, this->z * coef);
    }
    
    void operator*=(double coef) {
        *this = *this * coef;
    }

    void operator/=(double coef) {
        *this = *this / coef;
    }

    vec3 operator+(const vec3 other_vector) {
        return(vec3(this->x + other_vector.x,
                    this->y + other_vector.y,
                    this->z + other_vector.z));
    }

    void operator+=(const vec3 other_vector) {
        *this = *this + other_vector;
    }

    vec3 operator-() {
        return vec3((-this->x), (-this->y), (-this->z));
    }
    
    vec3 operator-(const vec3 other_vector) {
        return vec3(this->x - other_vector.x,
                    this->y - other_vector.y,
                    this->z - other_vector.z);
    }

    void operator-=(const vec3 other_vector) {
        *this = *this - other_vector;
    }

    vec3 normalize() {
        if (this == 0) return vec3(0, 0, 0);
        return *this / this->lenth();
    }


    std::vector<double> getCords() {
        std::vector<double> cords;
        cords.push_back(this->x);
        cords.push_back(this->y);
        cords.push_back(this->z);
        return cords;
    }


};

std::ostream& operator<< (std::ostream& stream, const vec3& vec) {
    stream << vec.x << ' ' << vec.y << ' ' << vec.z;
    return stream;
}

vec3 vectorMult(vec3 vector1, vec3 vector2) {
    return vec3(vector1.y * vector2.z - vector1.z * vector2.y, vector1.z * vector2.x - vector1.x * vector2.z, vector1.x * vector2.y - vector1.y * vector2.x);
}

double scalarMult(const vec3 vector1, const vec3 vector2) {
        return (vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z);
    }
