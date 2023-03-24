//
// Created by Jonas Hermon-Duc on 21/03/2023.
//

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal(){
    this->_type = "WrongAnimal";
}
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
}
WrongAnimal::WrongAnimal(WrongAnimal const &other){
    *this = other;
}
WrongAnimal& WrongAnimal::operator=(WrongAnimal const &rhs){
    this->_type = rhs._type;
    return *this;
}
WrongAnimal::~WrongAnimal(){
    std::cout << "Wrong Animal Destructor " << std::endl;
}

std::string    WrongAnimal::getType() const {
    return this->_type;
}

void    WrongAnimal::makeSound() const{
    std::cout << "Wrong Animal Song " << std::endl;
}