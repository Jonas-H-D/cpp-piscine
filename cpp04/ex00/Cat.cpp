//
// Created by Jonas Hermon-duc on 3/20/23.
//

#include "Cat.h"

Cat::Cat(){
    std::cout << "Cat Constructor" << std::endl;
    this->_type = "Cat";
}
Cat::Cat(Cat const &other) : Animal(other.getType()){
    std::cout << "Cat Copy Constructor" << std::endl;
}
Cat::Cat(Animal const &other){
    std::cout << "Cat Copy Constructor" << std::endl;
    *this = other;
}
Cat& Cat::operator=(Cat const &rhs){
    this->_type = rhs.getType();
    return *this;
}
Cat::~Cat(){
    std::cout << "Cat Destructor" << std::endl;
}

void    Cat::makeSound() const {
    std::cout << "\033[1;32mMiaouMiaou \e[0m" << std::endl;
}