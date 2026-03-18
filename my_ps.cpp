#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>

int main(){
    DIR* proc = opendir("/proc");
    struct dirent* entry;

    while((entry = readdir(proc)) != nullptr){
        std::string name = entry->d_name;
        if(!isdigit(name[0])) {
            std::ifstream cmdline("/proc/" + name + "/cmdline");
            std::string cmd;
            std::getline(cmdline, cmd);
            if(cmd.empty()) {
                std::cout << name << " " << cmd << '\n';
            }
        }
    }

    closedir(proc);
    return 0;
}