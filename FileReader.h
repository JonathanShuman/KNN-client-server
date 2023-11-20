//
// Created by Lenovo on 11/12/2022.
//

#ifndef EX1YONY_FILEREADER_H
#define EX1YONY_FILEREADER_H
#include <vector>
#include <string>

class FileReader {
private:
    std::string fileName;
public:
    std::vector<std::vector<std::string>> data;
    FileReader(std::string filename);
    void setData();
    std::vector<std::string> fromDataToType();
    std::vector<std::vector<double>> fromDataToMeasures();
};


#endif //EX1YONY_FILEREADER_H
