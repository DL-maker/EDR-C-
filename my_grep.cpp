#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int recherche(const std::string& pattern, const std::string& file){
    std::ifstream fichier(file.c_str());
    std::regex word_regex(pattern);
    std::string ligne;

    while(std::getline(fichier, ligne)){
        if(std::regex_search(ligne, word_regex)){
            std::cout << ligne << '\n';
        }
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
    if(argc == 3 && fichier_existe(argv[2])){
        recherche(argv[1], argv[2]);
    }
    return 0;
}