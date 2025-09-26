#include "Encrypter.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
int* Encrypter::encrypt(std::string input) {
   // unsigned long vS = input.length();
   std::string key = genKey();
   std::cout << "key made\n";
   int* out = encrypt(input, key);
   return out;
}

int* Encrypter::encrypt(std::string input, std::string key) {
   // unsigned long vS = input.length();
    //std::string out = input;
    int* out = new int[input.length() + 1];
    out[1] = input.at(0);
    //plan is letter ascii - previous letter ascii%30 - key value ascii = new current letter
    //hoping usually won't have ascii values below 32
    for(auto i=static_cast<int>(input.length())-1; i > 1;i--) {
        std::cout << "num: " << ((input.at(i) - input.at(i-1)/*%30*/ + key.at(i%key.length()))/*%224*/ + 31) << std::endl;
        //out[i] = static_cast<char>((input.at(i) - input.at(i-1)/*%30*/ + key.at(i%key.length()))/*%224*/ + 31);
        out[i] = (input.at(i) - input.at(i-1)/*%30*/ + key.at(i%key.length()))/*%224*/ + 31;
    }
    out[0] = input.length();
    return out;
}

std::string Encrypter::decrypt(std::string input, std::string key) {
    std::string out = input;
    std::cout << "decoding\n" << out << std::endl;

    for(auto i = 1; i < input.length(); i++) {
        out[i] = static_cast<char>(out.at(i) + out.at(i-1) - key.at(i%key.length()) - 31);
        std::cout << "key: " << key.at(i%key.length()) << ", encoded: " << input.at(i) << ", previous: " << out.at(i-1) << ";;;; next: " << out.at((i+1)%input.length()) << ", nextKey: " << key.at(((i+1)%key.length())) << "nextOut: " << (out.at((i+1)%out.length()) + out.at(i) - key.at((i+1)%key.length()) - 31) << std::endl;

    }
    return out;
}

std::string Encrypter::genKey() {
    srand(time(0));
    std::cout << "key asked for\n";
    std::string key;
    int size = (10);
    for(auto i = 0; i < size; i++) {
        key.append("L");
        key[i] = static_cast<char>(rand()%60 + 32);
    }
    std::ofstream outputFile("key.txt");
    outputFile << key;
    outputFile.close();
    return key;
}