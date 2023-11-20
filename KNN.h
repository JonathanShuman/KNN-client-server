//
// Created by ronni on 14/12/2022.
//

#ifndef AP_EX2_KNN_H
#define AP_EX2_KNN_H
#include <vector>
#include <string>

class KNN {

public:
    std::vector<std::string> findKClose(std::vector<std::vector<double>> dataVector, std::vector<std::string> Classification,
                                        std::vector<double> inputVector, int k, std::string distanceType);
    std::string classified(std::vector<std::string> kCloseClassification);

private:
    std::vector<std::string> indexToClassification(std::vector<int> indexVector, std::vector<std::string> classification);

    std::vector<double> maxElement(std::vector<double> vector);


};

#endif //AP_EX2_KNN_H
