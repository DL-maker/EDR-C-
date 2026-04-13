#include <iostream>
#include "ex09.hpp"

int main() {
    std::cout << "=== Person ===" << std::endl;
    Person p("Alice");
    p.setAge(25);
    p.greet();
    std::cout << "Age: " << p.getAge() << std::endl;
    
    std::cout << std::endl << "=== Student ===" << std::endl;
    Student s("Bob", "MIT");
    s.setAge(20);
    s.greet();
    s.introduce();
    std::cout << "Age: " << s.getAge() << std::endl;
    
    return 0;
};