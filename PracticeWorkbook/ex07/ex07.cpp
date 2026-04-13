#include "ex07.hpp"
#include <iostream>

int main() {
    BankAccount account("Alice", 1000);
    
    account.deposit(500); // Balance: 1500
    account.withdraw(200); // Balance: 1300
    account.withdraw(2000); // Fails: insufficient funds
    
    account.display();
    return 0;
}
