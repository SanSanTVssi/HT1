//
// Created by AAI2002 on 30.11.2021.
//

#include "FileGuard.h"

FileGuard::FileGuard(const std::string &filename) : file(new std::fstream) {
    // Need for processing exceptions connected with files.
    file->exceptions(std::ifstream::badbit | std::ifstream::failbit);
    // Try open file. If file is not exist or just or not available
    // Throw exception (without processing, because then the program has nothing to work with)
    try {
        file->open(filename);
    }
    catch (const std::exception &fileException) {
        throw std::fstream::failure("Exception while opening file! [FileGuard::FileGuard] Filename: "
        + filename + "\nError type:\t"
        + fileException.what());
    }
}

FileGuard::~FileGuard() {
    file->close();
    delete file;
}
