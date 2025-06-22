#include <iostream>
#include <string>

#include "mylib.hpp"

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "And from libmylib.so: " << std::endl;
    myprint("erm what the sigma");
    // std::cout << " Is there anything you'd like to say? > ";
    // std::string response;
    // std::cin >> response;

    // // reverse string
    // std::string reverse;
    // for (auto &&i : response)
    // {
    //     reverse
    // }    

    return 0;
}
