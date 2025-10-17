#include"commonLibs.h"

class model {
    public: 
    
    std::vector<polygon> polygons;
    vec3 origin;

    model(vec3 origin, std::vector<polygon> polygons) {
        this->polygons = polygons;
        this->origin = origin;
    }

    vec3 convertToGlobal(vec3 dot) {
        return this->origin + dot;
    }
//добавить преобрзовани всех точек и полигонов в глобальные кординаты и обратно.

};