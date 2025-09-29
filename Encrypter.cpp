#include "Encrypter.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
int* Encrypter::encrypt(std::string input) {
   // unsigned long vS = input.length();
   std::string key = genKey();
   return encrypt(input, key);
}

int* Encrypter::encrypt(std::string input, std::string key) {
    int* out = new int[input.length() + 1];
    out[1] = input.at(0);
    //plan is letter ascii - previous letter ascii + key value ascii + 31 = new current letter
    //key value is circular through modding the increment by the keys length so the key can be
    //used for any length of text
    //hoping usually won't have ascii values below 32
    for(auto i=static_cast<int>(input.length()); i > 1;i--) {
        out[i] = (input.at(i-1) - input.at(i-2) + key.at(i%key.length())) + 31;
    }
    out[0] = input.length();
    return out;
}

std::string Encrypter::decrypt(std::string inputF, std::string keyF) {
    std::string out;
    std::ifstream inputFile(inputF);
    int size;
    inputFile >> size;
    int* input = new int[size];
    for(int i = 0; i < size; i++){
        inputFile >> input[i];
        std::cout << i << ": " << input[i] << std::endl;
    }
    inputFile.close();
    inputFile.open(keyF);
    std::string key;
    std::getline(inputFile, key);
    inputFile.close();

    //std::cout << "decoding\n" << out << std::endl;
    out.push_back(static_cast<char>(input[0]));
    for(auto i = 1; i < size; i++) {
        out.push_back(static_cast<char>(input[i] + out.at(i-1) - key.at((i+1)%key.length()) - 31));
    }
    delete [] input;
    return out;
}

std::string Encrypter::genKey() {
    srand(time(0));
    std::string key;
    int size = (25);
    for(auto i = 0; i < size; i++) {
        key.append("L");
        key[i] = static_cast<char>(rand()%60 + 32);
    }
    std::ofstream outputFile("key.txt");
    outputFile << key;
    outputFile.close();
    return key;
}