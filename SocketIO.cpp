//
// Created by jonathan on 1/21/23.
//

#include "SocketIO.h"
#include <string>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

//constractor
SocketIO::SocketIO(int client) {
    this->client = client;
}

//read massage from client in socket
std::string SocketIO::read() {
    char buffer[4096];
    memset(buffer, 0, 4096);
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(this->client, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        return "";
    } else if (read_bytes < 0) {
        perror("error");
    } else {
        return buffer;
    }
}

//write massage to client in socket
void SocketIO::write(std::string str) {
    int sent_bytes = send(this->client, str.c_str(), str.length(), 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}
