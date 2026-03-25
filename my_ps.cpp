#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <string>
#include <limits.h>
#include <filesystem>
#include <unistd.h>
#include <pwd.h>
#include <cstdio>

void parse_args(int argc, char* argv[], bool& flag_a, bool& flag_x, bool& flag_u){
    for(int i = 1; i < argc; i++){
        std::string arg = argv[i];
        if(arg == "a") flag_a = true;
        if(arg == "x") flag_x = true;
        if(arg == "u") flag_u = true;
    }
}

int main(int argc, char* argv[]){
    bool flag_a = false;
    bool flag_x = false;
    bool flag_u = false;

    parse_args(argc, argv, flag_a, flag_x, flag_u);

    if(flag_u){
        std::cout << "USER\tPID\t%CPU\t%MEM\tTTY\tSTAT\n";
    } else if(flag_a || flag_x){
        std::cout << "PID\tTTY\t\tSTAT\tCMD\n";
    } else {
        std::cout << "PID\tTTY\tCMD\n";
    }

    for(
        auto it = std::filesystem::directory_iterator("/proc");
        it != std::filesystem::directory_iterator();
        ++it
    ){
        std::string name = it->path().filename().string();

        if(isdigit(name[0])){
            std::string path = "/proc/" + name + "/stat";
            std::ifstream stat(path);
            if(stat){
                int pid = 0, ppid = 0, pgrp = 0, session = 0, tty_nr = 0, tpgid = 0, flags = 0;
                std::string comm, state, tty, user, label;
                std::istringstream rss_line;
                std::istringstream uid_line;
                auto utime = 0;
                auto stime = 0;
                auto minfault = 0;
                auto cminfault = 0;
                auto majfault = 0;
                auto cmajfault = 0;
                auto cpu = 0.0;
                auto mem = 0.0;
                auto vm_rss = 0.0;
                auto uid = 0;

                if(flag_u){
                    stat >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr >> tpgid >> flags >> minfault >> cminfault >> majfault >> cmajfault >> utime >> stime;

                    char buf[255];
                    std::string cmd = "./my_grep Uid: /proc/" + name + "/status";
                    FILE* pipe = popen(cmd.c_str(), "r");
                    if(pipe){
                        if(fgets(buf, sizeof(buf), pipe)){
                            uid_line.str(buf);
                        }
                        pclose(pipe);
                    }
                    uid_line >> label >> uid;

                    std::string cmd3 = "./my_grep :" + std::to_string(uid) + ": /etc/passwd";
                    FILE* pipe3 = popen(cmd3.c_str(), "r");
                    if(pipe3){
                        if(fgets(buf, sizeof(buf), pipe3)){
                            std::istringstream iss(buf);
                            std::getline(iss, user, ':');
                        }
                        pclose(pipe3);
                    }

                    auto clock_ticks = sysconf(_SC_CLK_TCK);
                    if(clock_ticks > 0){
                        cpu = (utime + stime) / clock_ticks;
                    }

                    std::string cmd2 = "./my_grep VmRSS: /proc/" + name + "/status";
                    FILE* pipe2 = popen(cmd2.c_str(), "r");
                    if(pipe2){
                        if(fgets(buf, sizeof(buf), pipe2)){
                            rss_line.str(buf);
                        }
                        pclose(pipe2);
                    }
                    rss_line >> label >> vm_rss;
                    auto total_pages = sysconf(_SC_PHYS_PAGES);
                    auto page_size = sysconf(_SC_PAGE_SIZE);
                    if(total_pages > 0 && page_size > 0){
                        mem = (vm_rss * 1024) / (total_pages * page_size) * 100;
                    }
                }
                if(flag_a || flag_x){
                    stat >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr;
                } else {
                    stat >> pid >> comm >> ppid >> pgrp >> session >> tty_nr;
                }

                if(ttyname(tty_nr)){
                    tty = ttyname(tty_nr);
                } else {
                    tty = "null";
                }

                if(flag_u){
                    std::cout << user << "\t" << pid << "\t" << cpu << "\t" << mem << "\t" << tty << "\t" << state << "\n";
                } else if(flag_a || flag_x){
                    std::cout << pid << "\t" << tty << "\t" << state << "\t" << comm << "\n";
                } else {
                    std::cout << pid << "\t" << tty << "\t" << comm << "\n";
                }
            }
        }
    }

    return 0;
}