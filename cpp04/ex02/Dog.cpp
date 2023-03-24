//
// Created by Jonas Hermon-duc on 3/20/23.
//

#include "Dog.h"

Dog::Dog(){
    std::cout << "Dog Constructor" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}
Dog::Dog(const Dog &other){
    std::cout << "Dog copy constructor" << std::endl;
    this->_brain = new Brain(*other._brain);
    //*this = other;
}

Dog& Dog::operator=(Dog const &rhs){
    if (this == &rhs)
        return (*this);
    this->_type = rhs._type;
    return (*this);
}
Dog::~Dog(){
    std::cout << "Dog Destructor" << std::endl;
    delete this->_brain;
}

void    Dog::makeSound() const {
    std::cout << "\033[1;34mWoofWoof\033[0m" << std::endl;
}

void Dog::setIdea(std::string text, int i) const {
    if (i < 0 || i >= 100){
        std::cout << "Invalid idea number" << std::endl;
        return ;
    }
    this->_brain->ideas[i] = text;
}

std::string Dog::getIdea(int i) const {
    if (i < 0 || i >= 100){
        std::cout << "Invalid idea number" << std::endl;
        return NULL;
    }
    return this->_brain->ideas[i];
}