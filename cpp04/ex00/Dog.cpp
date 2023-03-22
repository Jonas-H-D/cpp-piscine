//
// Created by Jonas Hermon-duc on 3/20/23.
//

#include "Dog.h"

Dog::Dog(){
    this->_type = "Dog";
}
Dog::Dog(const Dog &other) : Animal(other.getType()) {
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Animal &other) : Animal(other) {
    std::cout << "Dog constructor called" << std::endl;
}

Dog& Dog::operator=(Dog const &rhs){
    if (this == &rhs)
        return (*this);
    this->_type = rhs.getType();
    return (*this);
}
Dog::~Dog(){
}

void    Dog::makeSound() const {
    std::cout << "\033[1;34mWoofWoof\033[0m" << std::endl;
}