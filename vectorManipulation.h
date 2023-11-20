//
// Created by ronni on 11/12/2022.
//

#ifndef AP_EX2_VECTORMANIPULATION_H
#define AP_EX2_VECTORMANIPULATION_H
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>

class vectorManipulation {
public:
    static std::vector<std::string> fromStringToVector(std::string inputStr);
    static bool vectorValidation(std::vector<std::string> sv);
    static std::vector<double> fromStrVectorToDoubleVector(std::vector<std::string> sv);
    static bool sizeValidation(std::vector<std::vector<std::string>> vec);

};


#endif //AP_EX2_VECTORMANIPULATION_H
