//
// Created by ronni on 23/01/2023.
//

#ifndef EX4_AP_DOWNLOADRESULTS_H
#define EX4_AP_DOWNLOADRESULTS_H

#include "Command.h"
#include "Data.h"

class DownloadResults: public Command{
private:
    int client;
    std::string filePath;

public:
    Data* data;
    DownloadResults(Data *data, int client);
    void execute() override;
    void toFile(int client);
};


#endif //EX4_AP_DOWNLOADRESULTS_H
