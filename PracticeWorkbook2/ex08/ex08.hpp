#pragma once
#include <iostream>
#include <string>

class Animal{
    private: 
        std::string nom;
    public:
        Animal(std::string nom2):nom(nom2){}
        std::string get_name(){
            return nom;
        }
};

class Dog : public Animal { 
    private:
    
    public:
        Dog(std::string nom2):Animal(nom2){}
        void bark(){
            std::cout << Animal::get_name() << ": WAF" << std::endl;
        }


};

class Cat : public Animal {
    private:

    public:
        Cat(std::string nom2):Animal(nom2){}
        void meow(){
            std::cout << Animal::get_name() <<  ": Meow" << std::endl;
        }
};


/* Pas de type de retour,Type,
*/




/*
Meme chose
std::string i = 5
std::string i(5)
*/
