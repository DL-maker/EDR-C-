#include <iostream>

int main(){
    int randomNum = rand() % 101;
    int reponce;
    int attempts = 0;
    std::cout << "Guess the number (between 1 and 100)!" << std::endl;
    while (reponce != randomNum){
        std::cout << "Your guess: ";
        std::cin >> reponce;
        if (reponce > randomNum){
            std::cout << "Lower !\n";
            attempts += 1;
        }
        if (reponce < randomNum){
            std::cout << "Higher\n";
            attempts += 1;
        }
        if (reponce == randomNum){
            std::cout << "Congratulations! \nYou found it in " << attempts << "! \n";
            break;
        }
    }
    return 0;
}

