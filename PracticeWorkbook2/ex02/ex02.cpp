#include <iostream>
#include "ex02.hpp"

auto FixedStack::push(int value) {
    if (_size == 5){
        std::cout << "Pushing " << value << " :";
        return false;
    }
    elements[_size] = value;
    _size++;
    return true;
}

bool FixedStack::pop() {
    if (_size == 0){
        return false;
    }
    _size--;
    std::cout << "Popping: "<< elements[_size] << "\n"; 
    return true;
}

int FixedStack::top() {
    return elements[_size - 1];
}

bool FixedStack::isEmpty(){
    return _size == 0;
}
bool FixedStack::isFull(){
    return _size == 6;
}
int  FixedStack::size(){
    return _size;
}

auto FixedStack::display() {
    std::cout << "Stack: ";
    for (int i = 0; i < _size; i++){
        std::cout << elements[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    FixedStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.display();
    std::cout << "Size: " << stack.size() << '\n';
    if (!stack.push(60))
        std::cout << "Stack is full!\n";
    std::cout << "Top: " << stack.top() << '\n';
    stack.pop();
    stack.display();
    std::cout << "Size: " << stack.size() << '\n';
    return 0;
}