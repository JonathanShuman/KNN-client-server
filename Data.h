//
// Created by ronni on 22/01/2023.
//

#ifndef EX4_AP_DATA_H
#define EX4_AP_DATA_H


#include <string>
#include <vector>

class Data {
private:
    int k;
    std::string distanceType;
    std::vector<std::vector<double>> measuresVec;
    std::vector<std::string> classifiedVec;
    std::vector<std::vector<double>> testVec;
    std::vector<std::string> classifiedTestVec;
public:
    Data();

    void setk(int k);
    int getk();

    std::string getDistanceType();
    void setDistanceType(std::string dis);

    std::vector<std::vector<double>> getMeasuresVec();
    void setMeasuresVec(std::vector<std::vector<double>> measuresVec);

    std::vector<std::string> getClassifiedVec();
    void setClassifiedVec(std::vector<std::string> classifiedVec);

    std::vector<std::vector<double>> getTestVec();
    void setTestVec(std::vector<std::vector<double>> testVec);

    std::vector<std::string> getClassifiedTestVec();
    void setClassifiedTestVec(std::vector<std::string> classifiedTestVec);

};


#endif //EX4_AP_DATA_H
