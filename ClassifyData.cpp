//
// Created by ronni on 22/01/2023.
//

#include "ClassifyData.h"
#include "KNN.h"

//constructor
ClassifyData::ClassifyData(Data *data, int client) : data((Data *) data), client(client) {
    this->client = client;
    this->description = "3. classify data\n";

}
//clasiffied the test file
void ClassifyData::execute() {
    SocketIO socketIo(client);
    KNN knn;
    std::vector<std::string> knnVec;
    std::vector<std::string> classVecTest;
    if(this->data->getMeasuresVec().empty()){
        socketIo.write("please upload data\n");
        return;
    }
    for (int i = 0; i < this->data->getTestVec().size() ; i++){
        knnVec = knn.findKClose(this->data->getMeasuresVec(), this->data->getClassifiedVec(),
                                                         this->data->getTestVec()[i], this->data->getk(), this->data->getDistanceType());
        classVecTest.push_back(knn.classified(knnVec));
    }
    this->data->setClassifiedTestVec(classVecTest);
    socketIo.write("complete data classifying\n");

}
