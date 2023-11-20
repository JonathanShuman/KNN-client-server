//
// Created by ronni on 11/12/2022.
//

#include "vectorManipulation.h"
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>

/*
 * this function takes string that seperate by spaces and convert it to vector of strings
 * */
std::vector<std::string> vectorManipulation:: fromStringToVector(std::string inputStr){
    std::vector<std::string> sv;
    std::string str = "";
    int s = 0;
    for (int i = 0; i < inputStr.length(); i++) {
        if (inputStr[i] == ' ') {
            sv.push_back(inputStr.substr(s, i - s));
            s = i + 1;
            str = "";
        } else {
            str = str + inputStr[i];
        }
    }
    sv.push_back(str);
    return sv;
}


/*
 * this function takes vector of strings and convert it to vector of doubles
 * */
std::vector<double> vectorManipulation:: fromStrVectorToDoubleVector(std::vector<std::string> sv){
    std::vector<double > v(sv.size());
    for ( int j = 0; j < sv.size(); j++) {
        v[j] = std::stod(sv[j]);
    }
    return v;
}


/*
 * this function checks if all the vectors are in the same size
 * */
bool vectorManipulation::sizeValidation(std::vector<std::vector<std::string>> vec){
    for(int i = 0; i < vec.size() - 1; i++){
        if(vec[i].size() != vec[i+1].size()) {
            return false;
        }
    }
    return true;
}


/*
 * this function checks uf a given string vector can be converted to vector of doubles without problems
 * */
bool vectorManipulation:: vectorValidation(std::vector<std::string> sv){
    size_t checkLen;
    for (int i = 0; i < sv.size(); i++){
        try {
            double x = std::stod(sv[i], &checkLen);

            if (checkLen != sv[i].length()) {
                return false;
            }
        }
        catch (std::exception e){
            return false;
        }
    }
    return true;
}
