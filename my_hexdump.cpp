#include <bitset>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

char remplace(unsigned char caractere) {
    if (caractere >= 0x20 && caractere <= 0x7E){
        return caractere;
    };
    return '.';
}

int hex_file(const std::string& file){
    std::ifstream fichier(file.c_str());
    unsigned char b1 = fichier.get();
    unsigned char b2 = fichier.get();
    unsigned char b3 = fichier.get();
    unsigned char b4 = fichier.get();
    unsigned char b5 = fichier.get();
    unsigned char b6 = fichier.get();
    unsigned char b7 = fichier.get();
    unsigned char b8 = fichier.get();
    unsigned char b9 = fichier.get();
    unsigned char b10 = fichier.get();
    unsigned char b11 = fichier.get();
    unsigned char b12 = fichier.get();
    unsigned char b13 = fichier.get();
    unsigned char b14 = fichier.get();
    unsigned char b15 = fichier.get();
    unsigned char b16 = fichier.get();
    int nomber = 0;
    while (fichier){
        std::cout << std::setfill('0') << std::setw(8) << std::hex << nomber << "  "
          << std::setw(2) << +b1 << ' ' << +b2 << ' ' << +b3 << ' ' << +b4 << ' '
          << +b5 << ' ' << +b6 << ' ' << +b7 << ' ' << +b8 << "  "
          << +b9 << ' ' << +b10 << ' ' << +b11 << ' ' << +b12 << ' '
          << +b13 << ' ' << +b14 << ' ' << +b15 << ' ' << +b16
          << " |"
          << remplace(b1) << remplace(b2) << remplace(b3) << remplace(b4)
          << remplace(b5) << remplace(b6) << remplace(b7) << remplace(b8)
          << remplace(b9) << remplace(b10) << remplace(b11) << remplace(b12)
          << remplace(b13) << remplace(b14) << remplace(b15) << remplace(b16)
          << "| \n";
        nomber += 16;
        b1 = fichier.get();
        b2 = fichier.get();
        b3 = fichier.get();
        b4 = fichier.get();
        b5 = fichier.get();
        b6 = fichier.get();
        b7 = fichier.get();
        b8 = fichier.get();
        b9 = fichier.get();
        b10 = fichier.get();
        b11 = fichier.get();
        b12 = fichier.get();
        b13 = fichier.get();
        b14 = fichier.get();
        b15 = fichier.get();
        b16 = fichier.get();
    }
    return 0;
}


int fichier_existe(const std::string& file) {
    std::ifstream fichier(file.c_str());
    return fichier.good();
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (fichier_existe(argv[i])) {
            hex_file(argv[i]);
        }
    }
    return 0;
}