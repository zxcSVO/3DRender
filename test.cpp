#include "libs/cppLibs.h"

int main() {
    std::vector<model> models;
    models.push_back(importFromFile(std::ifstream("cube.obj")));
    for (auto el:models[0].polygons) {
        std::cout << el << std::endl;
    }
    while (1){}
    return 0;
}