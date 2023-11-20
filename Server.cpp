//
// Created by jonathan on 1/2/23.
//

#include "Server.h"
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
#include "KNN.h"
#include "FileReader.h"
#include <thread>
#include <condition_variable>
#include "CLI.h"

Server::Server(int port) {
    this->port = port;
}
void Server::createSocket() {
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock < 0) {
        perror("error creating socket");
        exit(0);
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(this->port);
    if (bind(this->sock, (struct sockaddr*)& sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        exit(0);
    }
    if (listen(this->sock, 5) < 0) {
        perror("error listening to a socket");
        exit(0);
    }

}
void Server::handle(int client_sock){
    CLI cli(client_sock, this->sock);
    cli.start();
}

void Server::runServer(){

    while(true) {
        std::vector<std::thread> threadsVec;
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(this->sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        CLI cli1(client_sock, this->sock);
        std::thread thread(&Server::handle, this, client_sock);
        thread.detach();
        threadsVec.push_back(std::move(thread));

        //std::thread t([this, client_sock]() {
        //    CLI cli(client_sock, this->sock);
        //    cli.start();
        //});
        //t.detach();
        //thread_pool.push_back(std::move(t));
    }
}



//std::string Server::knnCalc(std::string userInput) {
//    int i = 0;
//    std::vector<std::string> inputVector = vectorManipulation::fromStringToVector(userInput);
//    if (inputVector.size() < 3){
//        return "invlaid input";
//    }
//    std::vector<std::string> v;
//    for(; i < inputVector.size() - 2; i++){
//        v.push_back(inputVector[i]);
//    }
//    if (!(vectorManipulation::vectorValidation(v))) {
//        return "invalid vector input";
//    }
//    std::vector<double> inputv = vectorManipulation::fromStrVectorToDoubleVector(v);
//    std::string distanceMethod = inputVector[i];
//    std::string kString = inputVector[i + 1];
//    int k = stoi(kString);
//    FileReader fr(this->file);
//    fr.setData();
//    std::vector<std::string> classVec = fr.fromDataToType();
//    std::vector<std::vector<double>> measuresVec = fr.fromDataToMeasures();
//    if (measuresVec[0].size() != inputv.size()) {
//        return "vector length dont match file row";
//    }
//    KNN knn;
//    std::vector<std::string> knnVec = knn.findKClose(measuresVec, classVec, inputv, k, distanceMethod);
//    return knn.classified(knnVec);
//
//}