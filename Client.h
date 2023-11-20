//
// Created by jonathan on 12/30/22.
//

#ifndef EX3APLINUXY_CLIENT_H
#define EX3APLINUXY_CLIENT_H


class Client {
private:
    int port;
    char* ip;
    int sock;
public:
    Client(char* ip, int port);
    void createSock();
    void myMess(std::string mess);
    void communicateServer();

};


#endif //EX3APLINUXY_CLIENT_H
