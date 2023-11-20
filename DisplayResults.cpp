//
// Created by ronni on 23/01/2023.
//

#include "DisplayResults.h"

//constructor
DisplayResults::DisplayResults(Data *data, int client) : data((Data *) data), client(client) {
    this->client = client;
    this->description = "4. display results";

}

//print results to screen, use results from the Data object
void DisplayResults::execute() {
    SocketIO socketIo(client);
    if(this->data->getMeasuresVec().empty()){
        socketIo.write("please upload data\n");
        return;
    }
    if(this->data->getClassifiedTestVec().empty()){
        socketIo.write("please classify the data\n");
        return;
    }
    std::vector<std::string> classVecTest= this->data->getClassifiedTestVec();
    int size=(int) this->data->getClassifiedTestVec().size();
    for (int i=0;i< size;i++){
        socketIo.write(std::to_string(i+1)+" "+ classVecTest[i]+"\n");
    }
    socketIo.write("Done.\n");

}
