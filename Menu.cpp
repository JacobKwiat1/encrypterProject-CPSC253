#include "Menu.hpp"
#include "Encrypter.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
void Menu::prompt() {
    std::cout << "to select an option, enter the assigned number\n1: encode text from a file\n"
         << "2: encode text from input\n"
         << "3: decode text from a file\n";
        int selection;
        if(std::cin >> selection) {
        switch(selection) {
            case 1:
                fileEncrypt();
                break;
            case 2:
                textEncrypt();
                break;
            case 3:
                fileDecrypt();
                break;
        }
    }
}

void Menu::fileEncrypt() {
    std::string inputF;
    std::cout << "enter file name here: ";
    std::cin >> inputF;
    std::string in;
    std::string temp;
    std::ifstream inputFile(inputF);

    while(!inputFile.is_open()) {
        std::cout << "file would not open, enter file name to try again: ";
        std::cin >> inputF;
        inputFile.open(inputF);
    }

    std::stringstream stringBuffer;
    stringBuffer << inputFile.rdbuf();
    in = stringBuffer.str();
    inputFile.close();


    std::cout << "if you have a key file enter the filename (including the .txt extension), otherwise enter 0: ";
    std::cin >> temp;
    Encrypter thing;
    int* out;
    if(temp == "0") {
        std::cout << "key will be generated into a file named \"key.txt\"\n";
        out = thing.encrypt(in);
    }
    else {
        inputFile.open(temp);
        while(!inputFile.is_open()) {
            std::cout << "file would not open, enter file name to try again: ";
            std::cin >> temp;
            inputFile.open(temp);
        }

        std::string key;
        std::getline(inputFile, key);

        out = thing.encrypt(in, key);
        inputFile.close();
    }

    std::ofstream outputFile("encrypted.txt");
    for(int i = 0; i < in.length()+1; i++) {
        outputFile << out[i] << " ";
    }
    outputFile.close();
        std::cout << "successfully encrypted to \"encrypted.txt\"\n";
    delete [] out;
    return;
}

void Menu::textEncrypt() {
    std::string temp;
    Encrypter thing;
    std::string in;
    int* out;
    //get input to encrypt
    std::cout << "enter something\n";
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, in);

    //request key file name
    std::cout << "if you have a key file enter the filename (including the .txt extension), otherwise enter \"0\": ";
    std::cin.clear();
    std::cin >> temp;
    if(temp == "0") {
        std::cout << "key will be generated into a file named \"key.txt\"\n";
        out = thing.encrypt(in);
    }
    else {
        //make sure file is open and try again if not (probably not necessary or even useful for what it's trying to do)
        std::ifstream inputFile(temp);
        while(!inputFile.is_open()) {
            std::cout << "file would not open, enter file name to try again: ";
            std::cin >> temp;
            inputFile.open(temp);
        }

        std::string key;
        std::getline(inputFile, key);

        out = thing.encrypt(in, key);
        inputFile.close();
    }

    //output to file "encrypted.txt"
    std::ofstream outputFile("encrypted.txt");
    for(int i = 0; i < in.length()+1; i++) {
        outputFile << out[i] << " ";
    }
    outputFile.close();
    delete [] out;
    std::cout << "encrypted file has been saved to \"encrypted.txt\"\n";
    return;
}

void Menu::fileDecrypt() {
    std::string iFile;
    std::string kFile;
    std::cout << "enter filename (.txt included) you'd like to decrypt: ";
    std::cin >> iFile;
    std::cout << "enter key filename (.txt included): ";
    std::cin >> kFile;
    Encrypter thing;
    std::string output = thing.decrypt(iFile, kFile);
    std::ofstream outputFile("decrypted.txt");
    outputFile << output;
    std::cout << "output to \"decrypted.txt\"\n";
    return;
}
