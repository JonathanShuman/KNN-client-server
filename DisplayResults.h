//
// Created by ronni on 23/01/2023.
//

#ifndef EX4_AP_DISPLAYRESULTS_H
#define EX4_AP_DISPLAYRESULTS_H
#include "Command.h"
#include "Data.h"

class DisplayResults: public Command{
private:
    int client;
    Data* data;
public:
    DisplayResults(Data *data, int client);
    void execute() override;
};


#endif //EX4_AP_DISPLAYRESULTS_H
