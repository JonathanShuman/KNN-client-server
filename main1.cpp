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
    if(argc != 3){
        std::cout << "You need to enter 2 arguments - closing the program" << std::endl;
        return 0;
    }
    for (int i = 0; i < strlen(argv[2]); i++) {
        if (argv[2][i] < '0' || argv[2][i] > '9') {
            std::cout<<"invalid port"<<std::endl;
            return 0;
        }
    }
    Client client(argv[1], atoi(argv[2]));
    client.createSock();
    client.communicateServer();

    return 0;
}