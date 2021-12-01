//
// Created by AAI2002 on 30.11.2021.
//

#include "File.h"

std::string File::ReadString() {
    // Throw exception if the file has already ended.
    if (eof()) {
        throw std::runtime_error("Error: Attempting to read data after the end of the file!\n "
                                 "Perhaps the program does not correctly define the file limits ! [File::ReadString]");
    }
    std::string temp;
    // Throw exception if the file is empty or size of sting bigger than maximum number of elements the string is able to hold.
    try {
        std::getline(*file.operator->(), temp);
    }
    catch (const std::exception& exception) {
        std::string str = "Error: while file read! [File::ReadString]. Exception code: ";
        str += exception.what();
        throw std::runtime_error(str);
    }
    return temp;
}

void File::WriteString(const std::string &string) {
    try {
        *file.operator->() << string << std::endl;
    }
    catch (const std::exception& exception){
        std::string str = "Error: while write read! [File::WriteString]. Exception code: ";
        str += exception.what();
        throw std::runtime_error(str);
    }
}
