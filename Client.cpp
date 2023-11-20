//
// Created by jonathan on 12/30/22.
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Client.h"
#include <vector>
#include "vectorManipulation.h"
#include <string>
#include "SocketIO.h"

//constructor
Client::Client(char *ip, int port) {
    this->ip = ip;
    this->port = port;
}

//create client socket
void Client::createSock() {
//    const char* ip_address = this->ip;
//    const int port_no = this->port;
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock < 0) {
        perror("error creating socket");
        exit(0);
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(this->ip);
    sin.sin_port = htons(this->port);
    if (connect(this->sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error in connection to socket");
        exit(0);
    }
}

// send the massege to server
void Client::myMess(std::string mess) {
    int data_len;
    if (std::equal(mess.begin(), mess.end(), "")){
        data_len = 0;
    }else{
        data_len = mess.length();
    }
    int sent_bytes = send(this->sock, mess.c_str(), data_len, 0);
    if (sent_bytes < 0) {
        perror("error");
    }
}

//connect to servrt
void Client::communicateServer() {
    std::string userInput;
    SocketIO io(this->sock);

    while(true){
        std::cout << io.read() << std::endl;
        getline(std::cin, userInput);
        if (userInput == "8" ) {
            myMess("8");
            close(this->sock);
            break;
        }
        if (std::equal(userInput.begin(), userInput.end(), "")){
            myMess("\n");
        }else{
            myMess(userInput);
        }



    }

}
