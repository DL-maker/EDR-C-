#include <iostream>
#include "ex08.hpp"
int main() {
    std::cout << "=== Animals ===" << std::endl;

    Dog dog1("Rex");
    Cat cat1("Whiskers");
    Dog dog2("Buddy");
    
    dog1.bark();
    cat1.meow();
    dog2.bark();
    
    return 0;
}