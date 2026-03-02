#pragma once

#include"commonLibs.h"  
#include"vec3.h"
#include"helpFuncs.h"


class polygon {
public:

    vec3 d1;
    vec3 d2;
    vec3 d3;
    sf::Color color;
    
    polygon(const vec3&, const vec3&, const vec3&, const sf::Color&);
    polygon(const vec3&, const vec3&, const vec3&);
    
    void invert();
    vec3 normal() const;
    std::vector<polygon> clip(const vec3& planeNormal, const vec3& planePoint) const;
    vec3 middle() const;

};


std::ostream& operator<<(std::ostream& stream, polygon pol);