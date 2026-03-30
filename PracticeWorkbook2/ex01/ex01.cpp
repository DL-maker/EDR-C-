#include <iostream>
#include "ex01.hpp"


auto ShoppingList::addItem(const std::string& element) {
    items.push_back(element);
}

auto ShoppingList::removeItem() {
    if (!items.empty()) {
        items.pop_back();
    }
    else{
        std::cout << "Impossible car elle est deja" << std::endl;
    }
}

auto ShoppingList::clear() {
    items.clear();
}

auto ShoppingList::display() {
    if (isEmpty()) {
        std::cout << "list vide" << std::endl;
    } else {
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << i + 1 << ". " << items[i] << std::endl;
        }
    }
}

int ShoppingList::count() {
    return items.size();
}

bool ShoppingList::isEmpty() {
    return items.empty();
}

int main() {
    ShoppingList list;
    list.addItem("Milk");
    list.addItem("Bread");
    list.addItem("Eggs");
    list.addItem("Butter");

    list.display();
    std::cout << "Total item: " << list.count() << std::endl;

    list.removeItem();
    list.display();

    list.clear();
    list.display();

    return 0;
}
