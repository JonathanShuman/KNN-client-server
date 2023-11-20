//
// Created by ronni on 22/01/2023.
//

#ifndef EX4_AP_ALGORITHEMSETTINGS_H
#define EX4_AP_ALGORITHEMSETTINGS_H
#include "Command.h"
#include "Data.h"


class AlgorithemSettings: public Command{
private:
    Data* data;
    //int k;
    //std::string distanceType;
    int client;
public:
    AlgorithemSettings(Data *data, int client);
    void execute() override;
};


#endif //EX4_AP_ALGORITHEMSETTINGS_H
