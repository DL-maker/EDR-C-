#include <iostream>
#include "ex05.hpp"

auto Inventory::addItem(std::string name, int quantity) {
    _items[name] = quantity;
}

auto Inventory::removeItem(std::string name) {
    _items.erase(name);
}

int Inventory::getQuantity(std::string name) {
    if (_items.find(name) == _items.end())
        return 0;
    return _items[name];
}

bool Inventory::hasItem(std::string name) {
    return _items.find(name) != _items.end();
}

auto Inventory::updateQuantity(std::string name, int delta) {
    if (_items.find(name) != _items.end())
        _items[name] += delta;
}

auto Inventory::display() {
    std::cout << "=== Inventory ===" << '\n';
    for (std::pair<std::string, int> p : _items) {
        std::cout << p.first << ": " << p.second << '\n';
    }
}

int Inventory::totalItems() {
    return _items.size();
}

int main() {
    Inventory inv;
    inv.addItem("apple", 10);
    inv.addItem("banana", 5);
    inv.addItem("orange", 8);
    inv.display();
    std::cout << "Total items: " << inv.totalItems() << '\n';
    std::cout << "Quantity of 'apple': " << inv.getQuantity("apple") << '\n';
    std::cout << "Quantity of 'grape': " << inv.getQuantity("grape") << '\n';
    inv.updateQuantity("apple", -3);
    std::cout << "After selling 3 apples:" << '\n';
    inv.display();
    inv.removeItem("banana");
    std::cout << "After removing 'banana':" << '\n';
    inv.display();
    std::cout << "Total items: " << inv.totalItems() << '\n';
    return 0;
}