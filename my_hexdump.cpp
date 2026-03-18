#include <bitset>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

int hex_file(const std::string& file){
    std::ifstream fichier(file.c_str());
    char b1 = fichier.get();
    char b2 = fichier.get();
    char b3 = fichier.get();
    char b4 = fichier.get();
    char b5 = fichier.get();
    int nomber = 0;
    while (fichier){
        std::cout << std::setfill('0') << std::setw(8) << std::dec << nomber << ' ' << std::hex << std::setw(2) << +b1 << ' ' << +b2 << ' ' << +b3 << ' ' << +b4 << ' ' << +b5 << std::dec << " " << b1 << b2 << b3 << b4 << b5 << " " << '\n';
        nomber += 16;
        b1 = fichier.get();
        b2 = fichier.get();
        b3 = fichier.get();
        b4 = fichier.get();
    };
};

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
            hex_file(argv[i]);
        }
    }
    return 0;
}