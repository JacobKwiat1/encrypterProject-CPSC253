#ifndef ENCRYPTER_H
#include <string>
class Encrypter {
    public:
        Encrypter() {}
        int* encrypt(std::string); 
        int* encrypt(std::string, std::string);
        std::string decrypt(std::string, std::string);
    private:
        std::string genKey();
};
#endif