//
// Created by ronni on 22/01/2023.
//
//this class contains all data need to classified vector and the classified vectors

#include "Data.h"
//constractor
Data::Data() {
    this->k= 5;
    this->distanceType = "AUC";

}

//getters and setters for all data
void Data::setk(int k){
    this->k = k;
}
int Data::getk(){
    return this->k;
}

std::string Data::getDistanceType(){
    return this->distanceType;
}
void Data::setDistanceType(std::string dis){
    this->distanceType=dis;
}

std::vector<std::vector<double>> Data::getMeasuresVec(){
    return this->measuresVec;
}
void Data::setMeasuresVec(std::vector<std::vector<double>> measuresVec){
    this->measuresVec=measuresVec;
}

std::vector<std::string> Data::getClassifiedVec(){
    return this->classifiedVec;
}
void Data::setClassifiedVec(std::vector<std::string> classifiedVec){
    this->classifiedVec = classifiedVec;
}

std::vector<std::vector<double>> Data::getTestVec(){
    return this->testVec;
}
void Data::setTestVec(std::vector<std::vector<double>> testVec){
    this->testVec = testVec;
}

std::vector<std::string> Data::getClassifiedTestVec(){
    return this->classifiedTestVec;
}
void Data::setClassifiedTestVec(std::vector<std::string> classifiedTestVec) {
    this->classifiedTestVec= classifiedTestVec;

}
