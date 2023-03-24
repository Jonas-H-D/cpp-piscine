//
// Created by Jonas Hermon-duc on 3/20/23.
//

#include "Dog.h"

Dog::Dog(){
    std::cout << "Dog Constructor" << std::endl;
    this->_type = "Dog";
}
Dog::Dog(const Dog &other) : Animal(other.getType()) {
    std::cout << "Dog copy constructor " << std::endl;
}

Dog::Dog(const Animal &other) : Animal(other) {
    std::cout << "Dog copy constructor " << std::endl;
}

Dog& Dog::operator=(Dog const &rhs){
    if (this == &rhs)
        return (*this);
    this->_type = rhs.getType();
    return (*this);
}
Dog::~Dog(){
    std::cout << "Dog Destructor" << std::endl;
}

void    Dog::makeSound() const {
    std::cout << "\033[1;34mWoofWoof\033[0m" << std::endl;
}