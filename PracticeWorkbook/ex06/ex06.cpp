#include <iostream>
#include "ex06.hpp"

int Rectangle::setWidth(int w){
    int _wight = w;
    std::cout << "La valeur wight a ete enregistrer avec valeur " << _wight << std::endl;
    return 0;
};

int Rectangle::setHeight(int h){
    int _height = h;
    std::cout << "La valeur height a ete enregistrer avec valeur " << _height << std::endl;
    return 0;
};

int Rectangle::getWidth(){
    std::cout << _wight << std::endl;
    return 0;
};

int Rectangle::getHeight(){
    std::cout << _height << std::endl;
    return 0;
};

int Rectangle::area(){
    std::cout << _height * _wight << std::endl;
    return 0;
};

int Rectangle::perimeter(){
    std::cout << 2 * (_wigh + _height) << std::endl;
    return 0;
};

int main() {
    Rectangle rect(5.0, 3.0);

    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Height: " << rect.getHeight() << std::endl;
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;

    rect.setWidth(10.0);
    rect.setHeight(6.0);

    std::cout << "New area: " << rect.area() << std::endl;
    return 0;
};