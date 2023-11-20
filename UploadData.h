//
// Created by ronni on 22/01/2023.
//

#ifndef AP_EX4_UPLOADDATA_H
#define AP_EX4_UPLOADDATA_H

#include "SocketIO.h"
#include "Command.h"
#include "Client.h"
#include "Data.h"
#include <vector>

class UploadData: public Command{
private:
    int client;
    Data* data;
    //std::vector<std::vector<double>> measuresVec;
    //std::vector<std::string> classifiedVec;
    //std::vector<std::vector<double>> testVec;
public:
    UploadData(Data *data, int client);
    void execute();
    //std::vector<std::vector<double>> getMeasuresVec();
    //std::vector<std::string> getClassifiedVec();
    //std::vector<std::vector<double>> getTestVec();
};


#endif //AP_EX4_UPLOADDATA_H
