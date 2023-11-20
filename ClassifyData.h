//
// Created by ronni on 22/01/2023.
//

#ifndef EX4_AP_CLASSIFYDATA_H
#define EX4_AP_CLASSIFYDATA_H
#include "Command.h"
#include "Data.h"


class ClassifyData: public Command{
private:
    int client;
    Data* data;
public:
    ClassifyData(Data *data, int client);
    void execute() override;

};

#endif //EX4_AP_CLASSIFYDATA_H
