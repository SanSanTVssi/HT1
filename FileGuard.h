//
// Created by AAI2002 on 30.11.2021.
//

#ifndef HT1_FILEGUARD_H
#define HT1_FILEGUARD_H

#include <fstream>
#include <utility>

class FileGuard {
private:
    std::fstream *file;
public:
    FileGuard() = delete;

    explicit FileGuard(const std::string &filename);

    ~FileGuard();

    std::fstream *get() { return file; }
};

#endif //HT1_FILEGUARD_H
