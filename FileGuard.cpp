//
// Created by AAI2002 on 30.11.2021.
//

#include "FileGuard.h"

FileGuard::FileGuard(const std::string &filename) : file(new std::fstream) {
    file->exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try {
        file->open(filename);
    }
    catch (const std::exception &fileException) {
        throw std::fstream::failure("Exception while opening file! [FileGuard::FileGuard] Filename: " + filename + "\nError type:\t" + fileException.what());
    }
}

FileGuard::~FileGuard() {
    file->close();
    delete file;
}
