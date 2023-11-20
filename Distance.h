//
// Created by ronni on 11/12/2022.
//
#include <vector>
#include <string>

#ifndef AP_EX2_DISTANCE_H
#define AP_EX2_DISTANCE_H


class Distance {
public:
    static double chebyshevDistance(std::vector<double> v1, std::vector<double> v2);

    static double canberraDistance(std::vector<double> v1, std::vector<double> v2);

    static double minkowskiDistance(std::vector<double> v1, std::vector<double> v2);

    static double euclideanDistance(std::vector<double> x, std::vector<double> y);

    static double manhattanDistance(std::vector<double> x, std::vector<double> y);

    static double distance(std::vector<double> v1, std::vector<double> v2, std::string s);

};


#endif //AP_EX2_DISTANCE_H
