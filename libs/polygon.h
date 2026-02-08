#pragma once

#include"commonLibs.h"  
#include"vec3.h"
#include"helpFuncs.h"


class polygon {
public:

    vec3 d1;
    vec3 d2;
    vec3 d3;
    
    polygon(vec3 d11, vec3 d12, vec3 d13);
    
    vec3 normal();
    std::vector<polygon> clip(vec3 planeNormal, vec3 planePoint);

};


std::ostream& operator<<(std::ostream& stream, polygon pol);