#include <iostream>
#include "Scambler.h"

void Demonstration(IFileIO *source, IFileIO *donor) {
    while (!source->EndOfFile()) {
        // Read next string from file into temp and encrypts it.
        std::string temp = source->readStr();
        // Write next string from file into temp and decrypts it.
        donor->writeStr(temp);
    }
}

int main() {
    using namespace std;
    try {
        auto instance_source = Scrambler("source.html", "abcs");
        auto instance_donor = Scrambler("donor.txt", "abcs");
        Demonstration(&instance_source, &instance_donor);
    }
    catch (const std::exception &exception) {
        std::cout << exception.what() << std::endl;
        std::cout << "The program was completed" << std::endl;
        return 1;
    }
    return 0;
}
