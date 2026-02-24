#pragma once

#include"commonLibs.h"
#include"vec3.h"
#include"polygon.h"
#include"model.h"

std::vector<int> splitFace(std::string& face);

model importFromFile(std::ifstream input);