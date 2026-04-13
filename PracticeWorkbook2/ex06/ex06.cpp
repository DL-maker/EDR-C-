#include "tracker.hpp"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

int main() {
  std::cout << "=== Creating objects ===" << std::endl;
  Tracker a("A");
  Tracker b("B");

  std::cout << std::endl << "=== Entering inner scope ===" << std::endl;
  {
  Tracker c("C");
  std::cout << "=== Exiting inner scope ===" << std::endl;
  }
    std::this_thread::sleep_for(std::chrono::seconds (2));
    std::cout << std::endl << "=== Program ending ===" << std::endl;
    return 0;
}