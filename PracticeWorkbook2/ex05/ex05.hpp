#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class Inventory {
private:
    std::unordered_map<std::string, int> _items;

public:
    void addItem(std::string name, int quantity);
    void removeItem(std::string name);
    int getQuantity(std::string name);
    bool hasItem(std::string name);
    void updateQuantity(std::string name, int delta);
    auto display();
    int totalItems();
};