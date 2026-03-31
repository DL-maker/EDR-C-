#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <arpa/inet.h>

bool tcp       = false;
bool udp       = false;
bool unix_sock = false;
bool listening = false;

void parse(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg[0] == '-') {
            for (char c : arg.substr(1)) {
                if (c == 't') {
                    tcp = true;
                }
                if (c == 'u') {
                    udp = true;
                }
                if (c == 'x') {
                    unix_sock = true;
                }
                if (c == 'l') {
                    listening = true;
                }
            }
        }
    }
    if (!tcp && !udp && !unix_sock) {
        tcp = true;
    }
}

auto hexIP(const std::string &hex_ip) {
    unsigned int p, q, r, s;
    char out[16];

    sscanf(hex_ip.c_str(), "%2x%2x%2x%2x", &p, &q, &r, &s);
    sprintf(out, "%u.%u.%u.%u", p, q, r, s);

    return std::string(out);
}

int hexPort(const std::string &hex_port) {
    int port;
    std::stringstream ss;
    ss << std::hex << hex_port;
    ss >> port;
    return port;
}

auto tcpState(const std::string &state) {
    if (state == "01") {
        return "ESTAB";
    }
    if (state == "0A") {
        return "LISTEN";
    }
    if (state == "06") {
        return "TIME-WAIT";
    }
    return "OTHER";
}

int fichier_existe(const std::string &path) {
    std::ifstream f(path);
    return f.good();
}

void parseFile(const std::string &path, const std::string &proto, bool listens) {
    if (!fichier_existe(path)) {
        std::cout << "Le fichier ne peux pas etre ouvert ou n'existe pas" << std::endl;
        return;
    }

    std::ifstream file(path);
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> cols;
        std::string val;

        while (iss >> val) {
            cols.push_back(val);
        }

        if (cols.size() < 4) {
            continue;
        }

        std::string local    = cols[1];
        std::string remote   = cols[2];
        std::string state    = cols[3];
        std::string stateStr = tcpState(state);

        if (listens && stateStr != "LISTEN") {
            continue;
        }

        std::string lip = hexIP(local.substr(0, 8));
        int lport       = hexPort(local.substr(9));
        std::string rip = hexIP(remote.substr(0, 8));
        int rport       = hexPort(remote.substr(9));

        std::cout << std::left << "\t\t" << proto << "\t\t" << lip << ":" << lport << "\t\t" << "---->" << "\t" << rip << ":" << rport << stateStr << "\n";
    }
}

void parseUnix() {
    if (!fichier_existe("/proc/net/unix")) {
        std::cout << "Le fichier ne peux pas etre ouvert ou n'existe pas" << std::endl;
        return;
    }

    std::ifstream file("/proc/net/unix");
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::cout << "unix  " << line << "\n";
    }
}

int main(int argc, char **argv) {
    parse(argc, argv);

    std::cout << "\t\t" << "Proto" << "\t\t"
              << "Local Address:Port" << "\t\t"
              << "Peer Address:Port" << "\t\t"
              << "State\n";

    if (tcp) {
        parseFile("/proc/net/tcp", "tcp", listening);
    }
    if (udp) {
        parseFile("/proc/net/udp", "udp", listening);
    }
    if (unix_sock) {
        parseUnix();
    }

    return 0;
}