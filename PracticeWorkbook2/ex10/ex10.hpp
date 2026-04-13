#pragma once
#include <iostream>
#include <string>

template <typename T>
class Box {
    private:
        int T _value;
    public:
        Box(T value) {
            _value = value;
        }

        T getValue() {
            return _value;
        }

        void setValue(T value) {
            _value = value;
        }
};

template <typename T>
T min(T a, T b) {
    if (a < b)
        return a;
    return b;
}

template <typename T>
T max(T a, T b) {
    if (a > b)
        return a;
    return b;
}