#pragma once

#include"commonLibs.h"
#include"matrix3.h"


class vec3 {
    public:
    double x, y, z;

    vec3(double x, double y, double z);
    vec3();

    double lenth();
    bool operator==(const vec3 vector);
    bool operator==(double len);
    vec3 operator/(double coef);
    vec3 operator*(double coef);
    // vec3 operator*(matrix3 mt);
    void operator*=(double coef);
    void operator/=(double coef);
    vec3 operator+(const vec3 other_vector);
    void operator+=(const vec3 other_vector);
    vec3 operator-();
    vec3 operator-(const vec3 other_vector);
    void operator-=(const vec3 other_vector);
    vec3 normalize();
    std::vector<double> getCords();
    // void rotateXY(double angle);
    // void rotateYZ(double angle);
    // void rotateXZ(double angle);
    
};

std::ostream& operator<< (std::ostream& stream, const vec3& vec);

vec3 vectorMult(vec3 vector1, vec3 vector2);

double scalarMult(const vec3 vector1, const vec3 vector2);
