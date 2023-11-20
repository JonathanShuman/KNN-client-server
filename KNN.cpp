//
// Created by ronni on 14/12/2022.
//
#include <vector>
#include "KNN.h"
#include "Distance.h"
#include <map>
#include <iostream>

std::vector<double> KNN:: maxElement(std::vector<double> vector){
    std::vector<double> max;
    max.push_back(vector[0]);
    max.push_back(0);
    for(int i=1;i<vector.size();i++){
        if(vector[i]> max[0]){
            max[0] = vector[i];
            max[1] = i;
        }
    }
    return max;
}

std::vector<std::string> KNN:: indexToClassification(std::vector<int> indexVector, std::vector<std::string> classification){
    std::vector<std::string> kCloseClassification;
    for(int i=0; i<indexVector.size();i++){
        kCloseClassification.push_back(classification[indexVector[i]]);
    }
    return  kCloseClassification;
}

std::vector<std::string> KNN:: findKClose(std::vector<std::vector<double>> dataVector, std::vector<std::string> classification,
    std::vector<double> inputVector, int k, std::string distanceType){
    std::vector<double> minDistances;
    std::vector<int> minDisIndex;
    std::vector<double> maxOfMinDis;
    for (int i=0;i<dataVector.size();i++){
        if (minDistances.size()<k){
            minDistances.push_back(Distance:: distance(dataVector[i],inputVector, distanceType));
            minDisIndex.push_back(i);
            continue;
        }
        if (i==k){ //in order to calculate max not every time
            maxOfMinDis = maxElement(minDistances);
        }
        double dis=Distance:: distance(dataVector[i],inputVector, distanceType); //לבדוק אם null
        if (dis<maxOfMinDis[0]){
            minDistances[(int) maxOfMinDis[1]] = dis;
            minDisIndex[(int) maxOfMinDis[1]] = i;
            maxOfMinDis = maxElement(minDistances);
        }
    }
    return indexToClassification(minDisIndex,classification);
}

std::string KNN:: classified(std::vector<std::string> kCloseTags){
    std::map<std::string,int> count ;
    for (int i=0; i<kCloseTags.size(); i++){
        if (count.find(kCloseTags[i])==count.end()){
            count[kCloseTags[i]] = 1;
        } else {
            count[kCloseTags[i]] += 1;
        }
    }
    int max = 0;
    std::string classification;
    for (auto it = count.begin(); it !=count.end(); ++it){
        if (it->second>max){
            max = it->second;
            classification = it->first;
        }
    }

    return classification;
}

