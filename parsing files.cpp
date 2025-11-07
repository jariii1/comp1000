#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(){

    std::ifstream inputFile("data.csv");
    std::string line, value;

    if (!inputFile.is_open()){
        std::cout << "Error, could not open file." <<std::endl;
        return 1;
    }
    
    //read each line from the file
    while(getline(inputFile, line)){
        std::istringstream ss(line);
        std::string name, age, city;

        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, city, ',');

        std::cout << "Name: " << name <<"Age: "<< age <<" City:" << city << std::endl;

    }
    inputFile.close();
    return 0;
}