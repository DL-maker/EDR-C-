#include <iostream>

int main(){
    int maxi = 5;
    int valeur_total = 0;
    int valeur_donne = 0;
    int i = 1;
    while (i <= maxi){
        std::cout << "Enter grade " << i << ": " ;
        std::cin >> valeur_donne;
        if (-1 < valeur_donne && 21 > valeur_donne){
            valeur_total += valeur_donne;
        }
        else{
            std::cout << "Cette valeur n'est pas  valide" << std::endl;
            i--;
        }
        i++;
    };
    std::cout << valeur_total / 5 << std::endl;
    return 0;
};