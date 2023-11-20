//
// Created by ronnie on 11/12/2022.
//

#include "Distance.h"
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>


//Calculate the chebyshev distance between the vectors according to the formula.
//assuming vectors in the same size.
double Distance:: chebyshevDistance(std::vector<double> v1, std::vector<double> v2) {
    int i = 0;
    double cdis = 0;
    double arr[v1.capacity()];
    for (i = 0; i < v1.capacity(); i++) {
        arr[i] = v1[i] - v2[i];
        if (arr[i] < 0)
            arr[i] = arr[i] * -1;
        if (arr[i] > cdis)
            cdis = arr[i];
    }
    return cdis;
}
//Calculate the canberra distance between the vectors according to the formula.
//assuming vectors in the same size.
double Distance:: canberraDistance(std::vector<double> v1, std::vector<double> v2) {
    int i = 0;
    double cdis = 0;
    double arrDis[v1.capacity()];
    double arrSum[v1.capacity()];
    for (i = 0; i < v1.capacity(); i++) {
        arrDis[i] = v1[i] - v2[i];
        if (arrDis[i] < 0)
            arrDis[i] = arrDis[i] * -1;
        if (v1[i] < 0) {
            v1[i] = v1[i] * -1;
        }
        if (v2[i] < 0) {
            v2[i] = v2[i] * -1;
        }
        arrSum[i] = v1[i] + v2[i];
        cdis = cdis + (arrDis[i] / arrSum[i]);
    }
    return cdis;
}
//Calculate the minkowski distance between the vectors according to the formula.
//assuming vectors in the same size.
double Distance:: minkowskiDistance(std::vector<double> v1, std::vector<double> v2) {
    int i = 0;
    double p = 2;
    double cdis = 0;
    double arrDis[v1.capacity()];
    for (i = 0; i < v1.capacity(); i++) {
        arrDis[i] = v1[i] - v2[i];
        if (arrDis[i] < 0)
            arrDis[i] = arrDis[i] * -1;
        cdis = cdis + powf(arrDis[i], p);
    }
    return powf(cdis, 1 / p);
}

//Calculate the eculidean distance between the vectors according to the formula.
//assuming vectors in the same size.
double Distance:: euclideanDistance(std::vector<double> x, std::vector<double> y) {
   double sqrSum = 0;
   for (int i = 0; i < x.size(); i++) {
       sqrSum = sqrSum + pow(x[i] - y[i], 2);
   }
   return sqrt(sqrSum);
}

//Calculate the Manhattan distance between the vectors according to the formula.
//assuming vectors in the same size.
double Distance:: manhattanDistance(std::vector<double> x, std::vector<double> y) {
    double sum = 0;
    for (int i = 0; i < x.size(); i++) {
        sum = sum + sqrt(pow(x[i] - y[i], 2));
    }
    return sum;
}

//Assumes string is valid
double Distance:: distance(std::vector<double> v1, std::vector<double> v2,std::string s) {
    if(s=="AUC"){
        return Distance::euclideanDistance(v1, v2);
    }
   if(s=="MAN"){
       return Distance::manhattanDistance(v1, v2);
   }
   if(s=="CHB"){
       return Distance::chebyshevDistance(v1, v2);
   }
   if(s=="CAN"){
       return Distance::canberraDistance(v1, v2);
   }
   return Distance::minkowskiDistance(v1, v2);
}

