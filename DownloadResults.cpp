//
// Created by ronni on 23/01/2023.
//

#include "DownloadResults.h"
#include <fstream>
#include <iostream>
#include <thread>

//constructor
DownloadResults::DownloadResults(Data *data, int client) : data((Data *) data), client(client) {
    this->client = client;
    this->description = "5. download results\n";
}

//func that write to file
void DownloadResults::toFile(int client) {
    SocketIO socketIo(client);
    std::ofstream file;
    try{
        file.open(this->filePath);
        std::vector<std::string> classVecTest= this->data->getClassifiedVec();
        int size=(int) this->data->getClassifiedTestVec().size();
        for (int i=0;i< size;i++){
            file <<std::to_string(i+1)+","+ classVecTest[i]<< std::endl;
        }
    }catch (std::exception){
        socketIo.write("Error opening/writing to file ");
    }
    file.close();
}

//get filepath from the user and call func 'toFile' in different thread
void DownloadResults::execute() {
    SocketIO socketIo(client);
    std::vector<std::thread> threadsVec;
    if (this->data->getMeasuresVec().empty()) {
        socketIo.write("please upload data\n");
        return;
    }
    if (this->data->getClassifiedTestVec().empty()) {
        socketIo.write("please classify the data\n");
        return;
    }
    socketIo.write("Please enter your output file location");
    this->filePath = socketIo.read();
    // tread :
    std::thread thread(&DownloadResults::toFile, this, client);
    thread.detach();
    threadsVec.push_back(std::move(thread));
}
