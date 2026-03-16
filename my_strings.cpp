#include <iostream>
#include <fstream>
#include <string>

int ligne_par_ligne(const std::string& fichier) {
    std::ifstream file(fichier.c_str());
    std::string stock;

    if (file.is_open()) {
        char caractere;
        int nombre = 0;
        while (file.get(caractere)) {
          if (stock.size() < 3){
            if (caractere >= 0 && caractere <= 127){
              stock += caractere;
            }
          } else {
            if (caractere >= 0 && caractere <= 127){
              std::cout << stock;
            }
          }
        }
        file.close();
    }
    return 0;
}

int fichier_existe(const std::string& file) {
    std::ifstream fichier(file.c_str());
    if (fichier.good()) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (fichier_existe(argv[i])) {
            ligne_par_ligne(argv[i]);
        }
    }
    return 0;
}
