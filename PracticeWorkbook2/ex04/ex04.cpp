#include <iostream>
#include "ex04.hpp"

void WordCounter::addWord(std::string word) {
    _words[word]++;
}

int WordCounter::getCount(std::string word) {
    return _words[word];
}

void WordCounter::removeWord(std::string word) {
    _words. (word);
}

void WordCounter::display() {
    std::cout << "=== Word Counts ===" << '\n';
    for (auto [word, count] : _words) {
        std::cout << word << ": " << count << '\n';
    }
}

void WordCounter::getMostFrequent() {
    std::string max_word = "";
    int max = 0;
    for (auto [word, count] : _words) {
        if (count > max) {
            max = count;
            max_word = word;
        }
    }
    return max_word;
}

void WordCounter::clear() {
    _words.clear();
}

int main() {
    WordCounter counter;
    counter.addWord("apple");
    counter.addWord("banana");
    counter.addWord("apple");
    counter.addWord("cherry");
    counter.addWord("apple");
    counter.addWord("banana");
    counter.display();
    std::cout << "Count for 'apple': " << counter.getCount("apple") << '\n';
    std::cout << "Count for 'orange': " << counter.getCount("orange") << '\n';
    std::cout << "Most frequent word: " << counter.getMostFrequent() << " (" << counter.getCount(counter.getMostFrequent()) << " times)" << '\n';
    counter.removeWord("banana");
    std::cout << "After removing 'banana':" << '\n';
    counter.display();
    return 0;
}