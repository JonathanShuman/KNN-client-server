//
// Created by jonathan on 1/2/23.
//

#ifndef EX3APLINUXY_SERVER_H
#define EX3APLINUXY_SERVER_H


#include <string>
#include <thread>
#include <vector>

class Server {
private:
    int sock;
    int port;
    std::vector<std::thread> thread_pool;
public:
    Server(int port);
    void runServer();
    void createSocket();
    std::string knnCalc(std::string userInput);
    void handle(int client_sock);



};


#endif //EX3APLINUXY_SERVER_H
