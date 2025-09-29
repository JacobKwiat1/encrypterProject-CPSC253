#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Encrypter.hpp"
#include "Menu.hpp"
int main() {
    // std::cout << "enter something\n";
    // std::string in;
    // std::getline(std::cin, in);
    //Encrypter thing;
    // std::string out = thing.encrypt(in);
    //int* out = thing.encrypt(in);
    // std::ofstream outputFile("encrypted.txt");
    // for(int i = 0; i < in.length()+1; i++) {
    //     outputFile << out[i] << " ";
    // }
    //outputFile.close();
    //delete [] out;
    // std::cout << "moving onto decoding\n";
    // std::string iFile = "encrypted.txt";
    // std::string kFile = "key.txt";

    // std::string output = thing.decrypt(iFile, kFile);
    //std::cout << output;
    Menu menu;
    menu.prompt();
    return 0;
}
