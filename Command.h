//
// Created by jonathan on 1/21/23.
//

#ifndef EX4APLINUX_COMMAND_H
#define EX4APLINUX_COMMAND_H
#include <string>
#include "SocketIO.h"


class Command {
protected:
    std::string description;
    SocketIO* dio;
public:
    virtual void execute() = 0;
};


#endif //EX4APLINUX_COMMAND_H
