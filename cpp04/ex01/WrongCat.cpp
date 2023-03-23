//
// Created by Jonas Hermon-Duc on 21/03/2023.
//

#include "WrongCat.h"

WrongCat::WrongCat(){
    this->_type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.getType()){
    std::cout << "WrongCopy 1 called" << std::endl;
}
WrongCat::WrongCat(const WrongAnimal &other): WrongAnimal(other){
    std::cout << "WrongCopy 2 called" << std::endl;
}
WrongCat& WrongCat::operator=(WrongCat const &rhs){
    this->_type = rhs._type;
    return *this;
}
WrongCat::~WrongCat(){

}

void    WrongCat::makeSound() const {
    std::cout << "\033[1;32mMiaouMiaou \e[0m" << std::endl;
}