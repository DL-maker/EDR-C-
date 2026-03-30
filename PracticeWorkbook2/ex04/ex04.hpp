#pragma once
#include <iostream>
#include <map>
#include <string>

class WordCounter {
private:
    std::map<std::string, int> _words;

public:
    void addWord(std::string word);
    int getCount(std::string word);
    auto removeWord(std::string word);
    auto display();
    auto getMostFrequent();
    void clear();
};