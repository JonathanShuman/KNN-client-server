# AP_ex4

Introduction
This project is a machine learning application that uses the K-Nearest Neighbors (KNN) algorithm to classify data. It includes a server and client implementation that can be used to communicate with the KNN algorithm and perform tasks such as training and testing the algorithm using different data sets. The project is written in C++

Building and Running the Project
To build and run the project, you will need to have the following dependencies installed:

C++ compiler 
Once you have the dependencies installed, you can build the project using the following command: make

vectorManipulation.cpp: A file containing functions for manipulating vectors. This file contains various functions that are used to manipulate vectors in the application. These functions can be used to perform operations such as adding, subtracting, and dot product of vectors.

    static std::vector<std::string> fromStringToVector(std::string inputStr);
    static bool vectorValidation(std::vector<std::string> sv);
    static std::vector<double> fromStrVectorToDoubleVector(std::vector<std::string> sv);
    static bool sizeValidation(std::vector<std::vector<std::string>> vec);
    
     fromStringToVector: This function takes a string as input and returns a vector of strings.
     vectorValidation: This function takes a vector of strings as input and returns a boolean indicating whether the vector is valid.
     fromStrVectorToDoubleVector: This function takes a vector of strings as input and returns a vector of doubles.
     sizeValidation: This function takes a vector of vectors of strings as input and returns a boolean indicating whether the size of the vectors is valid.



Server.cpp: The implementation of the server class. This file contains the implementation of the server class, which is used to set up and run the server-side of the application. It handles the connection with clients, receives data, process the data using machine learning algorithms, and sends the results back to the client.

    Server(int port);
    void runServer();
    void createSocket();
    std::string knnCalc(std::string userInput);
    void handle(int client_sock);
    
     Server(int port) : constructor, it initialize the server with a given port number
     runServer(): This function is used to set up and run the server-side of the application. It handles the connection with clients, receives data, process the data      using machine learning algorithms, and sends the results back to the client.
     createSocket(): This function is used to create a socket that will be used to communicate with the client.
     knnCalc(std::string userInput): This function is used to perform KNN calculation based on the user's input.
     handle(int client_sock): This function is used to handle the communication with a specific client.


KNN.cpp: The implementation of the K-Nearest Neighbors algorithm. This file contains the implementation of the K-Nearest Neighbors (KNN) algorithm. KNN is a supervised learning algorithm that is used to classify data based on the distance between data points.

    std::vector<std::string> findKClose(std::vector<std::vector<double>> dataVector, std::vector<std::string> Classification,
                                        std::vector<double> inputVector, int k, std::string distanceType);
    std::string classified(std::vector<std::string> kCloseClassification);
    
   findKClose(std::vector<std::vector<double>> dataVector, std::vector<std::string> Classification, std::vector<double> inputVector, int k, std::string            distanceType): This function takes a data vector, a classification vector, an input vector, a value of k, and a distance type as input, and returns a vector of the    closest k classifications to the input vector.
  classified(std::vector<std::string> kCloseClassification): This function takes a vector of classifications as input and returns the most common classification.

FileReader.cpp: A file containing functions for reading data from files. This file contains functions that can be used to read data from files in various formats such as CSV, JSON, and others. These functions are used to read the data that is used for training and testing the machine learning algorithms.

    std::vector<std::vector<std::string>> data;
    FileReader(std::string filename);
    void setData();
    std::vector<std::string> fromDataToType();
    std::vector<std::vector<double>> fromDataToMeasures();
     
     FileReader(std::string filename) : constructor, it initialize the FileReader with a given file name
     setData(): This function is used to read data from the specified file.
     fromDataToType(): This function is used to extract the classification data from the file data.
     fromDataToMeasures(): This function is used to extract the measures data from the file data.

Client.cpp: The implementation of the client class. This file contains the implementation of the client class, which is used to set up and run the client-side of the application. It handles the connection with the server, sends data to the server, receives the results from the server, and displays the results to the user.

    Client(char* ip, int port);
    void createSock();
    void myMess(std::string mess);
    void communicateServer();
     
     Client(char* ip, int port): constructor, it initialize the client with a given ip and port number
     createSock(): This function is used to create a socket that will be used to communicate with the server.
     myMess(std::string mess): This function is used to send a message to the server.
     communicateServer(): This function is used to handle the communication with the server, sending data, receiving the results and displaying the results to the  user.

CLI.cpp: A file containing functions for command line interface. This file contains functions that can be used to create a command-line interface for the application. This can be used to interact with the application and perform various tasks such as uploading data, setting parameters, and displaying results.

    CLI(int client, int socket);
    Data data;
    [[noreturn]] void start();
     
     CLI(int client, int socket): constructor, it initialize the CLI with a given client and socket
     start(): This function is used to create a command-line interface for the application. This can be used to interact with the application and perform various     tasks such as uploading data, setting parameters, and displaying results.

SocketIO.cpp: A file containing functions for socket input/output. This file contains functions that can be used to handle socket input/output. These functions are used to send and receive data between the server and the client.

    SocketIO(int client);
    void write(std::string data);
    std::string read();
     
     SocketIO(int client): constructor, it initialize the SocketIO with a given client
     write(std::string data): This function is used to send data over a socket.
     read(): This function is used to receive data over a socket.

UploadData.cpp: A file containing functions for uploading data to the server. This file contains functions that can be used to upload data to the server. These functions are used to send data from the client to the server for training and testing the machine learning algorithms.

    UploadData(Data *data, int client);
    void execute();
     
     UploadData(Data *data, int client): constructor, it initialize the UploadData with a given data and client
     execute(): This function is used to send data from the client to the server for training and testing the machine learning algorithms.

AlgorithmSettings.cpp: A file containing functions for setting the parameters of the machine learning algorithms. This file contains functions that can be used to set the parameters of the machine learning algorithms. These functions are used to set the parameters such as the number of nearest neighbors for the KNN algorithm, the learning rate for neural networks, and others.

    AlgorithemSettings(Data *data, int client);
    void execute() override;
     
     

Data.cpp: A file containing functions for manipulating and storing data. This file contains functions that can be used to manipulate and store data. These functions can be used to perform operations such as splitting data into training and testing sets, normalizing data, and others.

    std::string getDistanceType();
    void setDistanceType(std::string dis);

    std::vector<std::vector<double>> getMeasuresVec();
    void setMeasuresVec(std::vector<std::vector<double>> measuresVec);

    std::vector<std::string> getClassifiedVec();
    void setClassifiedVec(std::vector<std::string> classifiedVec);

    std::vector<std::vector<double>> getTestVec();
    void setTestVec(std::vector<std::vector<double>> testVec);

    std::vector<std::string> getClassifiedTestVec();
    void setClassifiedTestVec(std::vector<std::string> classifiedTestVec);
     
     getDistanceType(): This function returns the current distance type used for the KNN algorithm.
    setDistanceType(std::string dis): This function sets the distance type that will be used for the KNN algorithm.
     getMeasuresVec(): This function returns the current measures data vector used to train and test the KNN algorithm.
     setMeasuresVec(std::vector<std::vector<double>> measuresVec): This function sets the measures data vector that will be used to train and test the KNN algorithm.
     getClassifiedVec(): This function returns the current classification data vector used to train and test the KNN algorithm.
     setClassifiedVec(std::vector<std::string> classifiedVec): This function sets the classification data vector that will be used to train and test the KNN algorithm.
     getTestVec(): This function returns the current test data vector used to test the KNN algorithm.
     setTestVec(std::vector<std::vector<double>> testVec): This function sets the test data vector that will be used to test the KNN algorithm.
     getClassifiedTestVec(): This function returns the current classification test data vector used

ClassifyData.cpp: A file containing functions for classifying data using machine learning algorithms. This file contains functions that can be used to classify data using various machine learning algorithms such as KNN, SVM, and others. These functions are used to classify data based on the results of the training and testing data.

    ClassifyData(Data *data, int client);
    void execute() override;
     
     ClassifyData(Data *data, int client): constructor, it initialize the ClassifyData with a given data and client
    execute(): This function is used to classify data using various machine learning algorithms such as KNN. These functions are used to classify     data based on the results of the training and testing data.

DisplayResults.cpp: A file containing functions for displaying the results of the machine learning algorithms. This file contains functions that can be used to display the results of the machine learning algorithms. These functions can be used to display the results in various formats such as tables, charts, and others.

    DisplayResults(Data *data, int client);
    void execute() override;
     
     DisplayResults(Data *data, int client): constructor, it initialize the DisplayResults with a given data and client
     execute(): This function is used to display the results of the machine learning algorithms in various formats such as tables, charts, and others.

DownloadResults.cpp: A file containing functions for downloading the results from the server. This file contains functions that can be used to download the results from the server. These functions are used to download the results of the machine learning algorithms that were processed on the server.

    DownloadResults(Data *data, int client);
    void execute() override;
    void toFile(int client);
     
     DownloadResults(Data *data, int client): constructor, it initialize the DownloadResults with a given data and client
     execute(): This function is used to download the results of the machine learning algorithms that were processed on the server.
     toFile(int client): This function is used to save the downloaded results to a file

To run the server, execute the server.out binary file. To run the client, compile and execute main2.cpp. Make sure that the server is running before starting the client.

    
    
