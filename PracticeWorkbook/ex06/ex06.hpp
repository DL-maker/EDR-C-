#pragma once
#include <iostream>
#include <list>
#include <string>

class Rectangle {
private:
    double _wight;
    double _height;

public:
    double setWidth(int w);
    double setHeight(int h);
    double getWidth();
    double getHeight();
    double area();
    double perimeter();
};