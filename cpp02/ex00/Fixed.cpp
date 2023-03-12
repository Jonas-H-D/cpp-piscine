#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->_fix_nbr = 0;
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed & Fixed::operator=(const Fixed &rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fix_nbr = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fix_nbr;
}

void Fixed::setRawBits(int const raw){
    this->_fix_nbr = raw;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

