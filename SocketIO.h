//
// Created by jonathan on 1/21/23.
//

#ifndef EX4APLINUX_SOCKETIO_H
#define EX4APLINUX_SOCKETIO_H
#include <string>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>



class SocketIO {
private:
    int client;
public:
    SocketIO(int client);
    void write(std::string data);
    std::string read();
};


#endif //EX4APLINUX_SOCKETIO_H
