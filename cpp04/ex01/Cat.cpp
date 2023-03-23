//
// Created by Jonas Hermon-duc on 3/20/23.
//

#include "Cat.h"

Cat::Cat(){
    std::cout << "Cat Constructor" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}
Cat::Cat(Cat const &other){
    std::cout << "Cat Copy Constructor" << std::endl;
    this->_brain = new Brain(*other._brain);
}

Cat::Cat(Animal const &other) : Animal(other){
    this->_type = other.getType();
    this->_brain = new Brain();
    std::cout << "Cat Copy Constructor" << std::endl;
}

Cat& Cat::operator=(Cat const &rhs){
    this->_type = rhs.getType();
    return *this;
}
Cat::~Cat(){
    std::cout << "Cat Destructor" << std::endl;
    delete this->_brain;
}

void    Cat::makeSound() const {
    std::cout << "\033[1;32mMiaouMiaou \e[0m" << std::endl;
}

void Cat::setIdea(std::string text, int i) const {
    if (i < 0 || i >= 100){
        std::cout << "Invalid idea number" << std::endl;
        return ;
    }
    this->_brain->ideas[i] = text;
}

std::string Cat::getIdea(int i) const {
    if (i < 0 || i >= 100){
        std::cout << "Invalid idea number" << std::endl;
        return NULL;
    }
    return this->_brain->ideas[i];
}