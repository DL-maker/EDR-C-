#include <iostream>
#include "point.hpp"
int main() {
    Point p1(3, 4);
    Point p2(1, 2);
    
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    
    std::cout << std::endl << "p1 + p2 = " << (p1 + p2) << std::endl;
    std::cout << "p1 - p2 = " << (p1 - p2) << std::endl;
    
    std::cout << std::endl << "p1 == p2: " << (p1 == p2 ? "true" : "false") << std::endl;
    std::cout << "p1 == p1: " << (p1 == p1 ? "true" : "false") << std::endl;
    
    return 0;
}   
