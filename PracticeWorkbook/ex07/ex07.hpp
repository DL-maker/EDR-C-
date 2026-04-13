#pragma once
#include <iostream>
#include <string>

class BankAccount {
    private:
        std::string _owner; 
        int _balance;
    
    public:
        BankAccount(std::string owner, int balance): _owner(owner), _balance(balance){}

        bool deposit(int amount){
            std::cout << "Deposit " << amount << "..." << std::endl;
            if(amount <= 1){
                std::cout << "Deposit failed !" << std::endl;
                display();
                return false;
            }
            else{
                _balance += amount;
                std::cout << "Deposit successful !" << std::endl;
                display();
                return true;
            }
        }

        bool withdraw(int amount){
            if(amount <= 0 || amount > _balance){
                std::cout << "Withdraw impossible !" << std::endl;
                display();
                return false;
            }
            else{
                _balance -= amount;
                std::cout << "Withdraw successful !" << std::endl;
                display();
                return true;
            }

        }

        void display(){
            std::cout << "Account owner: " << _owner << std::endl;
            std::cout << "Balance: " << _balance << std::endl;
        };
};