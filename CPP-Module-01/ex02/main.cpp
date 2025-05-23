#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* ptr = &str;
    std::string& ref = str;

    std::cout << "Address of the string: " << &str << std::endl;
    std::cout << "Address of the string using pointer: " << ptr << std::endl;
    std::cout << "Address of the string using reference: " << &ref << std::endl;
    std::cout << "String using pointer: " << *ptr << std::endl;
    std::cout << "String using reference: " << ref << std::endl;
    std::cout << "String using original variable: " << str << std::endl;
    return 0;
}