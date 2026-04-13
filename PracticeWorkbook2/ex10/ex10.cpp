#include <iostream>
#include <string>
#include "ex10.hpp"

int main() {
    std::cout << "=== Template Functions ===" << std::endl;
    std::cout << "min(3, 5) = " << min(3, 5) << std::endl;
    std::cout << "min(3.14, 2.71) = " << min(3.14, 2.71) << std::endl;
    std::cout << "max(10, 20) = " << max(10, 20) << std::endl;
    std::cout << "max('a', 'z') = " << max('a', 'z') << std::endl;

    std::cout << std::endl << "=== Template Class Box ===" << std::endl;
    Box<int> intBox(42);
    Box<std::string> strBox("Hello");

    std::cout << "Box<int> contains: " << intBox.getValue() << std::endl;
    std::cout << "Box<std::string> contains: " << strBox.getValue() << std::endl;

    return 0;
}