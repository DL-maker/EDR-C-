#include <iostream>
#include <string>
#include <chrono>

class Tracker {
  private:
    std::string _name;
    std::chrono::time_point<std::chrono::high_resolution_clock> _start;

  public:
    Tracker(std::string a) {
      _start = std::chrono::high_resolution_clock::now();
      std::cout << a << " Created" << std::endl;
      _name = a;
    }

    ~Tracker() {
      std::cout << _name << " Destroyed" << std::endl;
      auto end = std::chrono::high_resolution_clock::now();
      auto delta = end - _start;
      std::cout << delta.count() << std::endl;
    }
};