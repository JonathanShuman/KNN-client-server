//
// Created by jonathan on 1/21/23.
//

#ifndef EX4APLINUX_CLI_H
#define EX4APLINUX_CLI_H

#include <string>
#include "Data.h"


class CLI {
private:
    
    int sock;
    
    int client;
    


public:
    CLI(int client, int socket);
    Data data;

    [[noreturn]] void start();


};


#endif //EX4APLINUX_CLI_H
