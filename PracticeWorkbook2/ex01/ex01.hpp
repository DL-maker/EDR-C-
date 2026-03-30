#pragma once
#include <vector>
#include <string>
#include <iostream>

class ShoppingList {
private:
    std::vector<std::string> items;

public:
    auto addItem(const std::string& item);
    auto removeItem();
    auto clear();
    auto display();
    int count();
    bool isEmpty();
};

