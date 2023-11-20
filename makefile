compile:
	g++ -o server.out main2.cpp vectorManipulation.cpp Server.cpp KNN.cpp FileReader.cpp Distance.cpp Client.cpp CLI.cpp SocketIO.cpp UploadData.cpp AlgorithemSettings.cpp Data.cpp ClassifyData.cpp DisplayResults.cpp DownloadResults.cpp -pthread -std=c++11
	g++ -o client.out main1.cpp vectorManipulation.cpp Server.cpp KNN.cpp FileReader.cpp Distance.cpp Client.cpp CLI.cpp SocketIO.cpp UploadData.cpp AlgorithemSettings.cpp Data.cpp ClassifyData.cpp DisplayResults.cpp DownloadResults.cpp -pthread -std=c++11
