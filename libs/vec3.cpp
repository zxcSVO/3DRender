#pragma once

#include"vec3.h"


vec3::vec3(const float& x, const float& y, const float& z){
    this->x = x;
    this->y = y;
    this->z = z;
}

vec3::vec3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

float vec3::lenth() const {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

bool vec3::operator==(const vec3& other_vector) const {
    return this->x - other_vector.x < 0.0001 && this->y - other_vector.y < 0.0001 && this->z - other_vector.z < 0.0001;
}
bool vec3::operator==(float& len) const {
    return this->lenth() - len < 0.000001;
}
bool vec3::operator!=(const vec3& other_vector) const {
    return !(this->x - other_vector.x < 0.0001 && this->y - other_vector.y < 0.0001 && this->z - other_vector.z < 0.0001);
}
bool vec3::operator!=(const float& len) const {
    return !(this->lenth() - len < 0.000001);
}

vec3 vec3::operator/(const float& coef) const {
    return vec3(this->x / coef, this->y / coef, this->z / coef);
}

vec3 vec3::operator*(const float& coef) const {
    return vec3(this->x * coef, this->y * coef, this->z * coef);
}


void vec3::operator*=(const float& coef) {
    *this = *this * coef;
}

void vec3::operator/=(const float& coef) {
    *this = *this / coef;
}

vec3 vec3::operator+(const vec3& other_vector) const {
    return(vec3(this->x + other_vector.x,
                this->y + other_vector.y,
                this->z + other_vector.z));
}

void vec3::operator+=(const vec3& other_vector) {
    *this = *this + other_vector;
}

vec3 vec3::operator-() const {
    return vec3((-this->x), (-this->y), (-this->z));
}

vec3 vec3::operator-(const vec3& other_vector) const {
    return vec3(this->x - other_vector.x,
                this->y - other_vector.y,
                this->z - other_vector.z);
}

void vec3::operator-=(const vec3& other_vector) {
    *this = *this - other_vector;
}

vec3 vec3::normalize() const {
    if (this == 0) return vec3(0, 0, 0);
    return *this / this->lenth();
}



std::ostream& operator<< (std::ostream& stream, const vec3& vec) {
    stream << vec.x << ' ' << vec.y << ' ' << vec.z;
    return stream;
}

vec3 vectorMult(const vec3& vector1, const vec3& vector2) {
    return vec3(vector1.y * vector2.z - vector1.z * vector2.y, vector1.z * vector2.x - vector1.x * vector2.z, vector1.x * vector2.y - vector1.y * vector2.x);
}

float scalarMult(const vec3& vector1, const vec3& vector2) {
    return (vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z);
}



