#pragma once

#include"commonLibs.h"

class vec3 {
    public:
    float x, y, z;

    vec3(const float&, const float&, const float& z);
    vec3();

    float lenth() const;
    bool operator==(const vec3&) const;
    bool operator==(float&) const;
    bool operator!=(const vec3&) const;
    bool operator!=(const float&) const;
    vec3 operator/(const float&) const;
    vec3 operator*(const float&) const;
    void operator*=(const float&);
    void operator/=(const float&);
    vec3 operator+(const vec3&) const;
    void operator+=(const vec3&);
    vec3 operator-() const;
    vec3 operator-(const vec3&) const;
    void operator-=(const vec3&);
    vec3 normalize() const;

};

std::ostream& operator<< (std::ostream&, const vec3&);

vec3 vectorMult(const vec3&, const vec3&);

float scalarMult(const vec3&, const vec3&);
