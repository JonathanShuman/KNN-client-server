//
// Created by jonathan on 1/21/23.
//

#include "CLI.h"
#include <string>
#include "SocketIO.h"
#include "UploadData.h"
#include "AlgorithemSettings.h"
#include "ClassifyData.h"
#include "DisplayResults.h"
#include "DownloadResults.h"

//conatructor
CLI::CLI(int client, int socket) {
    this->client = client;
    this->sock = socket;
    //this->distanceType = "AUC";
    //this->k = 5;
}

//hendale client - print menu and sent to the suitable func
[[noreturn]] void CLI::start() {
    std::string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n"
                  "1. upload an unclassified csv data file\n2. algorithm settings\n"
                  "3. classify data\n4. display results\n5. download results\n8. exit";
    SocketIO io(client);
    UploadData uploadData(&data,client);
    AlgorithemSettings algorithemSettings(&data, client);
    ClassifyData classifyData(&data, client);
    DisplayResults displayResults(&data, client);
    DownloadResults downloadResults(&data, client);
    while (true) {
        io.write(menu);
        std::string rec = io.read();
        char c= rec[0];
        switch (c) {
            case '1':
                uploadData.execute();
                break;
            case '2':
                algorithemSettings.execute();
                break;
            case '3':
                classifyData.execute();
                break;
            case '4':
                displayResults.execute();
                break;
            case '5':
                downloadResults.execute();
                break;
            case '8':
                while(true){}
            default:{
                io.write("invalid input\n");
            }


        }



    }
}
