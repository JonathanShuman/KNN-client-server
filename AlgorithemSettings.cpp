//
// Created by ronni on 22/01/2023.
//

#include <vector>
#include "AlgorithemSettings.h"
#include "vectorManipulation.h"

//constructor
AlgorithemSettings::AlgorithemSettings(Data *data, int client) : data((Data *) data), client(client) {
    this->description = "2. algorithm settings\n";
    this->client =client;
    //this->k =5;
    //this->distanceType = "AUC";
}

//set k and distance type according to the user
void AlgorithemSettings::execute() {
    SocketIO socketIo(client);
    socketIo.write("The current KNN parameters are: K = "+ std::to_string(this->data->getk())
    +", distance metric = "+ this->data->getDistanceType());
    std::string answer = socketIo.read();
    if (std::equal(answer.begin(), answer.end(), "\n")){
        return;
    }
    std::cout << "answer:"+answer << std::endl;
    if (std::equal(answer.begin(), answer.end(), "")){
        return;
    }
    std::vector<std::string> vec = vectorManipulation::fromStringToVector(answer);
    std::string kstr = vec[0];
    std::string dis = vec[1];
    bool kValid = true;
    for(int i = 0; i < kstr.length() ; i++){

        if(kstr[i] < '0' || kstr[i] > '9'){
            kValid = false;
            socketIo.write("invalid value for K\n");
            kValid = false;
            break;
        }
    }
    if (!(dis == "AUC" || dis == "MAN" || dis == "CHB" || dis == "CAN" || dis == "MIN")){
        socketIo.write("invalid value for metric\n");
        return;
    }
    if (kValid){
        this->data->setk(stoi(vec[0]));
        this->data->setDistanceType(vec[1]);
    }

}


