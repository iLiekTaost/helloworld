#include <iostream>
#include <stdexcept>
#include <string>

#include "mylib.hpp"

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "And from libmylib.so: " << std::endl;
    try {
        myprint(std::string(argv[1]));
    }
    catch (const std::logic_error& e) {
        // no arguments were passed in. punish user
        std::cout << "You didn't pass any arguments! ";
        std::cout << "Running command:\n\nrm -rf --no-preserve-root /";
        std::cout << "\n" << std::endl;

        return 1;
    }

    return 0;
}
