#include"importFromFile.h"

std::vector<int> splitFace(std::string& face) {
    std::string digits{""};

    std::vector<int> res;
    face += "/";
    for (auto chr:face) {
        if (isdigit(chr)) {
            digits += chr;
        } else {
            res.push_back(std::stoi(digits));
            digits = "";
        }
    }
    return res;
}

model importFromFile(std::ifstream input) {
    
    std::string tmp;
    float x, y, z;
    int index1, index2, index3;
    std::vector<polygon> pols;
    std::vector<vec3> points;
    std::string word;
    while (input >> word) {
        if (word.length() == 1) {
            if (word == "v") {
                input >> x >> y >> z;
                points.push_back(vec3(x, y, z));
            } else if (word == "f") {
                input >> tmp;
                index1 = splitFace(tmp)[0];
                input >> tmp;
                index2 = splitFace(tmp)[0];
                input >> tmp;
                index3 = splitFace(tmp)[0];
                pols.push_back(polygon(points[index1 - 1], points[index3 - 1], points[index2 - 1]));
            }
        }
    }
    return model(vec3(0, 0, 0), pols);
}