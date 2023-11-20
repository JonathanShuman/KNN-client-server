//
// Created by ronni on 22/01/2023.
//

#include "UploadData.h"
#include "SocketIO.h"
#include "FileReader.h"
#include <string>
#include <vector>

//constractor
UploadData::UploadData(Data *data, int client) : data((Data *) data), client(client){
    this->client=client;
    this->description = "1. upload an unclassified csv data file\n";
}

//get filepaths to train and test files and check if they valid
void UploadData:: execute(){
    SocketIO socketIo(client);
    socketIo.write("Please upload your local train CSV file");
    std::string filePath1 = socketIo.read();
    FileReader fileReader1(filePath1);
    try{
        fileReader1.setData();
    }catch(std::exception e) {
        socketIo.write("invalid input");
        return;
    }
    this->data->setMeasuresVec(fileReader1.fromDataToMeasures());
    this->data->setClassifiedVec(fileReader1.fromDataToType());
    socketIo.write("Upload complete.");
    socketIo.write("Please upload your local test CSV file");
    std::string filePath2 = socketIo.read();
    FileReader fileReader2(filePath2);
    try{
        fileReader2.setData();
    }catch(std::exception e) {
        socketIo.write("invalid input\n");
        return;
    }
    this->data->setTestVec(fileReader2.fromDataToMeasures());
    socketIo.write("Upload complete.\n");

}



