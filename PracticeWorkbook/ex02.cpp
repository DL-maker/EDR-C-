#include <iostream>

int main(){
    double number1, number2;
    char caractere;
    std::cout << "Enter the first number: ";
    std::cin >> number1;
    std::cout << "Enter the seconds number: ";
    std::cin >> number2;
    std::cout << "Enter the operator (+, -, *, /): ";
    std::cin >> caractere;
    switch(caractere) {
        case '*' :
          std::cout << "Resultat: " << number1 << " " << caractere << " " << number2 << " = " << number1 * number2<< "\n";
          break;
        case '+':
          std::cout << "Resultat: " << number1 << " " << caractere << " " << number2 << " = " <<  number1 + number2 << "\n" ;
          break;
        case '-':
          std::cout << "Resultat: " << number1 << " " << caractere << " " << number2 << " = " <<  number1 - number2 << "\n";
          break; 
        case '/':
            if (number2 == 0){
                std::cout << "Error: division by zero! \n";
                break;
            }
            else{
                std::cout << "Resultat: " << number1 << " " << caractere << " " << number2 << " = " <<  number1 / number2 << "\n";
            }
            break;
        default:
            std::cout << "Valeur invalide" << std::endl;
}
    return 0;
}