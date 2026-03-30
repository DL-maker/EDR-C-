#pragma once
#include <iostream>
#include <array> 

class FixedStack {
private:
    std::array<int, 5> elements;
    int _size = 0;

public:
    auto push(int value);
    bool pop();
    int top();
    bool isEmpty();
    bool isFull();
    int size();
    auto display();
};