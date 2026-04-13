#pragma once
#include <iostream>
#include <string>

class Person{
    private: 
        int _age;
    protected:
        std::string _name;
    public:

        Person(std::string name) : _name(name) {}
        void greet(){
            std::cout << "Hello, I'm " << _name << std::endl;
        }

        void setAge(int age){
            _age = age;
        }

        int getAge(){
            return _age;
        }
};

class Student : public Person { 
    private:
        std::string _school;
    public:
        Student(std::string name, std::string school): Person(name), _school(school){}
        void introduce(){
            std::cout << "I study at "<< _school <<std::endl;
        }

};