//
// Created by Jonas Hermon-duc on 3/20/23.
//
#include "Animal.h"

Animal::Animal(){
    std::cout << "Default Animal Constructor" << std::endl;
    this->_type = "Kangaroo";
}

Animal::Animal(std::string type) : _type(type) {
    std::cout <<this->_type << " Animal Constructor" << std::endl;
}

Animal::Animal(Animal const &other){
    std::cout << "Animal Copy Constructor" << std::endl;
    *this = other;
}

Animal& Animal::operator=(Animal const &rhs){
    if (this == &rhs)
        return (*this);
    this->_type = rhs.getType();
    return (*this);
}
Animal::~Animal(){
    std::cout << "Animal Destructor" << std::endl;
}

std::string    Animal::getType() const {
    return this->_type;
}

void    Animal::makeSound() const{
    std::cout << " SILENCE " << std::endl;
}