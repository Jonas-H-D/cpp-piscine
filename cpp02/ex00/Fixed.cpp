//
// Created by Jonas Hermon-duc on 3/11/23.
//

#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->_nbr_fixed_coma = 0;
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed & Fixed::operator=(const Fixed & rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_nbr_fixed_coma = rhs._nbr_fixed_coma;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_nbr_fixed_coma);
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_nbr_fixed_coma = raw;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}
