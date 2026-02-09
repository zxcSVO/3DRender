#pragma once

#include"commonLibs.h"

class vec3 {
    public:
    float x, y, z;

    vec3(float x, float y, float z);
    vec3();

    float lenth();
    bool operator==(const vec3 vector);
    bool operator==(float len);
    bool operator!=(const vec3 vector);
    bool operator!=(float len);
    vec3 operator/(float coef);
    vec3 operator*(float coef);
    void operator*=(float coef);
    void operator/=(float coef);
    vec3 operator+(const vec3 other_vector);
    void operator+=(const vec3 other_vector);
    vec3 operator-();
    vec3 operator-(const vec3 other_vector);
    void operator-=(const vec3 other_vector);
    vec3 normalize();
    std::vector<float> getCords();

};

std::ostream& operator<< (std::ostream& stream, const vec3& vec);

vec3 vectorMult(vec3 vector1, vec3 vector2);

float scalarMult(const vec3 vector1, const vec3 vector2);
