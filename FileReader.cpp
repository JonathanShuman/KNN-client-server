#include "FileReader.h"
#include "vectorManipulation.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
/*
 * constructor, initialize file name
 * */
FileReader::FileReader(std::string filename) {
    fileName = filename;
}


/*
 * this function set the data member of file reader class
 * its read the content from the given file name and convert it to vector of vectors
 * */
void FileReader:: setData(){
    std::vector<std::vector<std::string>> data;
    std::ifstream in(fileName);

    if (!in) {
        //this->data = data;
        throw std::exception();
    }

    std::string line;
    while (getline(in, line)) {
        std::vector<std::string> row;
        std::string word;
        for (char ch : line) {
            if (ch == ',') {
                row.push_back(word);
                word = "";
            } else {
                word += ch;
            }
        }
        row.push_back(word);
        data.push_back(row);
    }
    this->data = data;
}


/*
 * this function separate classifications from the data member and returns vector of the classifications
 * */
std::vector<std::string> FileReader:: fromDataToType() {
    std::vector<std::string> vec;
    for (int i = 0; i < this->data.size(); i++) {
        vec.push_back(this->data[i][this->data[i].size() - 1]);
    }
    return vec;
}


/*
 * this function separate the measures vectors from the data vectors and return vector of measures
 * */
std::vector<std::vector<double>> FileReader::fromDataToMeasures(){
    std::vector<std::vector<std::string>> vec;
    std::vector<std::string> vec1;
    std::vector<double> vec2;
    std::vector<std::vector<double>> vecd;
    for (int i = 0; i < this->data.size(); i++) {
        vec.push_back(vec1);
        for(int j = 0; j < this->data[i].size() - 1; j++) {
            vec[i].push_back(this->data[i][j]);
        }
    }
    if (!(vectorManipulation::sizeValidation(vec))){
        std::cout << "The data vectors are not in the same size! " <<  std::endl;
        exit(0);
    }
    for(int i = 0; i < vec.size(); i++){
        vecd.push_back(vec2);
        if(vectorManipulation::vectorValidation(vec[i])) {
            vecd[i] = vectorManipulation::fromStrVectorToDoubleVector(vec[i]);
        }
        else {
            std::cout << "There is invalid vector in row " << i + 1 << std::endl;
            exit(0);
        }
    }
    return vecd;
}
