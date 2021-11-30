//
// Created by AAI2002 on 30.11.2021.
//

#include "Scambler.h"


Scrambler::Scrambler(const std::string &filename,
                     std::string encryption_key) : file(new File(filename)),
                                                   Encryption_key(std::move(encryption_key)) {}
                                                   
std::string Scrambler::encrypt(const std::string &string) const {
    std::string result = std::string();
    for (int k = 0; k < string.length(); ++k) {
        int x = string[k] ^ Encryption_key[k % Encryption_key.length()];
        result.push_back(static_cast<char>(x));
    }
    return result;
}

std::string Scrambler::readStr() {
    return encrypt(file->ReadString());
}

void Scrambler::writeStr(const std::string &string) {
    file->WriteString(encrypt(string));
}

bool Scrambler::EndOfFile() {
    return file->eof();
}

Scrambler::~Scrambler() {
    delete file;
}


