#include <iostream>
#include <string>
#include <sys/inotify.h>
#include <unistd.h>

#define BUF_LEN 4096

int main(int argc, char* argv[]){
    bool monitor = false;
    std::string path;

    for(int i = 1; i < argc; i++){
        std::string arg = argv[i];
        if(arg == "--monitor"){
            monitor = true;
        } else {
            path = arg;
        }
    }

    int fd = inotify_init1(0);
    int wd = inotify_add_watch(fd, path.c_str(), IN_CREATE | IN_MODIFY | IN_DELETE);

    char buffer[BUF_LEN];

    do {
        int length = read(fd, buffer, BUF_LEN);
        int i = 0;
        while(i < length){
            struct inotify_event* event = (struct inotify_event*)&buffer[i];
            if(event->len){
                if(event->mask & IN_CREATE) {
                    std::cout << "CREATE: " << event->name << "\n";
                }
                if(event->mask & IN_MODIFY) {
                    std::cout << "MODIFY: " << event->name << "\n";
                }
                if(event->mask & IN_DELETE){ 
                    std::cout << "DELETE: " << event->name << "\n";
                }
                i += sizeof(struct inotify_event) + event->len;
            }
        }
    } while(monitor);

    inotify_rm_watch(fd, wd);
    close(fd);
    return 0;
}