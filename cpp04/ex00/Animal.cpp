//
// Created by Jonas Hermon-duc on 3/20/23.
//
#include "Animal.h"

Animal::Animal(){
    this->_type = "Animal";
}

Animal::Animal(std::string type) : _type(type) {
}

Animal::Animal(Animal const &other){
    *this = other;
}

Animal& Animal::operator=(Animal const &rhs){
    if (this == &rhs)
        return (*this);
    _type = rhs.getType();
    return (*this);
}
Animal::~Animal(){
}

std::string    Animal::getType() const {
    return this->_type;
}

void    Animal::makeSound() const{
    std::cout << " " << std::endl;
}