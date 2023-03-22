//
// Created by Jonas Hermon-duc on 3/20/23.
//

#include "Cat.h"

Cat::Cat(){
    this->_type = "Cat";
}
Cat::Cat(Cat const &other) : Animal(other.getType()){
}
Cat::Cat(Animal const &other){
    *this = other;
}
Cat& Cat::operator=(Cat const &rhs){
    this->_type = rhs.getType();
    return *this;
}
Cat::~Cat(){

}

void    Cat::makeSound() const {
    std::cout << "\033[1;32mMiaouMiaou \e[0m" << std::endl;
}