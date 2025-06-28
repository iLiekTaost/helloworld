#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

void myprint(const string& mystr) {
    cout << "\nThis message is from mylib!" << endl;
    cout << "Also, mystr from memory address " << &mystr << " says: ";
    cout << mystr << endl;
    
    return;
}
