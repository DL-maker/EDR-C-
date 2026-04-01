#include <iostream>

int main(){
    double number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "\n";
    std::cout << "Multiplication table of " << number << " : \n";
    for(int i=0; i <= 10; i++){
        std::cout << number << " * " << i << " = " << number*i << "\n";
    };
}