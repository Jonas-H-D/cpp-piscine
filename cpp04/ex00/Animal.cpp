//
// Created by Jonas Hermon-duc on 3/20/23.
//
#include "Animal.h"

Animal::Animal(){
    std::cout << "Animal Constructor" << std::endl;
    this->_type = "Animal";
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << this->_type << " Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &other){
    std::cout << "Animal copy Constructor" << std::endl;
    *this = other;
}

Animal& Animal::operator=(Animal const &rhs){
    if (this == &rhs)
        return (*this);
    _type = rhs.getType();
    return (*this);
}
Animal::~Animal(){
    std::cout << "Animal Destructor" << std::endl;
}

std::string    Animal::getType() const {
    return this->_type;
}

void    Animal::makeSound() const{
    std::cout << "\033[31m SILENCE \033[0m" << std::endl;
}