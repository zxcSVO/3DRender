#pragma once

#include"commonLibs.h"  
#include"vec3.h"
#include"camera.h"


class polygon {
public:

    vec3 d1;
    vec3 d2;
    vec3 d3;
    
    polygon(vec3 d11, vec3 d12, vec3 d13);
    
    vec3 normal();
    bool isDraw(camera cam);

};


std::ostream& operator<<(std::ostream& stream, polygon pol);