#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Encrypter.hpp"
int main() {
    std::cout << "enter something\n";
    std::getline(std::cin, in);
    Encrypter thing;
    // std::string out = thing.encrypt(in);
    int* out = thing.encrypt(in);
    std::ofstream outputFile("encrypted.txt");
    for(int i = 0; i < in.length(); i++) {
        std::cout << "something";
        outputFile << out[i] << " ";
    }
    delete [] out;
    outputFile.close();
    std::cout << "moving onto decoding\n";
    std::ifstream inputFile("encrypted.txt");
    int temp;
    int size;
    int i = 0;
    inputFile >> size;
    int* in = new int[size];
    for(int i = 0; i < size; i++){
        inputFile >> in[i];
    }
    inputFile.close();
    inputFile.open("key.txt");
    std::string out = key;
    std::getline(inputFile, key);
    inputFile.close();
    std::string output = thing.decrypt(in, key);
    std::cout << std::endl << out;
    return 0;
}
