//
// Created by AAI2002 on 30.11.2021.
//

#ifndef HT1_FILE_H
#define HT1_FILE_H

#include <utility>

#include "FileGuard.h"

class File {
private:
    FileGuard file;
public:
    File() = delete;

    explicit File(const std::string &filename) : file(filename) {}

    /**
    * Method for read one (next) string from file
    * @return next line
    * Can throw exceptions if
    * 1) File is clear
    * 2) An attempt to read data from a file if the file has already ended
    */
    std::string ReadString();

    /**
    * Method string into file (after inserts std::endl)
    * @param string for write into file
    */
    void WriteString(const std::string &string);

    /**
     * @return pointer for work with file stream
     */
    [[maybe_unused]] std::fstream *operator->() { return file.operator->(); }

    /**
     * Checks end of file
     * @return true if the end of file
     */
    bool eof() { return file->eof(); }
};


#endif //HT1_FILE_H
