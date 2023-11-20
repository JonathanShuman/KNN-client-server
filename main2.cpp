//
// Created by jonathan on 1/3/23.
//
#include <iostream>
#include "FileReader.h"
#include <vector>
#include <string>
#include <fstream>
#include "vectorManipulation.h"
#include "KNN.h"
#include <string.h>
#include "Client.h"
#include "Server.h"

int main(int argc, char* argv[]) {
    if(argc != 2){
        std::cout << "You need to enter 3 arguments - closing the program" << std::endl;
        return 0;
    }
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (argv[1][i] < '0' || argv[1][i] > '9') {
            std::cout<<"invalid port"<<std::endl;
            return 0;
        }
    }
    Server server(atoi(argv[1]));
    server.createSocket();
    server.runServer();
    return 0;
}