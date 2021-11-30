//
// Created by AAI2002 on 30.11.2021.
//

#ifndef HT1_SCAMBLER_H
#define HT1_SCAMBLER_H

#include <iostream>
#include "File.h"

class IFileIO {
public:
    virtual std::string readStr() = 0;

    virtual void writeStr(const std::string &string) = 0;

    virtual bool EndOfFile() = 0;

    virtual ~IFileIO() = default;
};

class Scrambler : public IFileIO {
private:
    File *file;
    std::string Encryption_key;

    /**
    * XOR encrypt for string
    * @param string - string for encryption
    * @return encrypted string
    */
    [[nodiscard]] std::string encrypt(const std::string &string) const;

public:
    Scrambler() = delete;

    Scrambler(const std::string &filename,
              std::string encryption_key);

    std::string readStr() override;

    void writeStr(const std::string &string) override;

    bool EndOfFile() override;

    ~Scrambler() override;
};


#endif //HT1_SCAMBLER_H
