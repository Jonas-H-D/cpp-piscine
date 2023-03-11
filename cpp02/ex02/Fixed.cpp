//
// Created by Jonas Hermon-duc on 3/11/23.
//

#include "Fixed.hpp"

Fixed::Fixed(){
    this->_nbr_fixed_coma = 0;
}

Fixed::Fixed(const Fixed &other){
    *this = other;
}

Fixed::Fixed(const int num){
    _nbr_fixed_coma = num << _fractional_bits;
}

Fixed::Fixed(const float num){
    _nbr_fixed_coma = (round(num * (1 << _fractional_bits)));
}

Fixed & Fixed::operator=(const Fixed & rhs){
    this->_nbr_fixed_coma = rhs._nbr_fixed_coma;
    return *this;
}

bool	Fixed::operator>(const Fixed & rhs) const {
    return (this->_nbr_fixed_coma > rhs._nbr_fixed_coma);
}

bool	Fixed::operator<(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left < right);
}

bool	Fixed::operator>=(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left >= right);
}

bool	Fixed::operator<=(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left <= right);
}

bool	Fixed::operator==(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left == right);
}

bool	Fixed::operator!=(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left != right);
}

Fixed	Fixed::operator+(const Fixed & rhs) const{
    return (Fixed(this->to_Float() + rhs.to_Float()));
}

Fixed	Fixed::operator-(const Fixed & rhs) const{
    return (Fixed(this->to_Float() - rhs.to_Float()));
}

Fixed	Fixed::operator*(const Fixed & rhs) const{
    return (Fixed(this->to_Float() * rhs.to_Float()));
}

Fixed	Fixed::operator/(const Fixed & rhs) const {
    if (rhs.to_Float() == 0) {
        std::cout << "Devision by 0 is not possible" << std::endl;
        Fixed f(0);
        return f;
    }
    return (Fixed(this->to_Float() / rhs.to_Float()));
}

Fixed	Fixed::operator++(int){
    Fixed	tmp = *this;

    this->_nbr_fixed_coma++;
    return (tmp);
}

Fixed	&Fixed::operator++(void){
    _nbr_fixed_coma++;
    return (*this);
}

Fixed	Fixed::operator--(int){
    Fixed	tmp = *this;

    this->_nbr_fixed_coma--;
    return (tmp);
}

Fixed	&Fixed::operator--(void){
    _nbr_fixed_coma--;
    return (*this);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
    if (a < b)
        return (a);
    return (b);
}

Fixed const	&Fixed::min(const Fixed &a, const Fixed &b){
    if (a < b)
        return (a);
    return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
    if (a > b)
        return (a);
    return (b);
}

Fixed const	&Fixed::max(const Fixed &a, const Fixed &b){
    if (a > b)
        return (a);
    return (b);
}

int Fixed::getRawBits() const {
    return (_nbr_fixed_coma);
}

void Fixed::setRawBits(const int raw) {
    this->_nbr_fixed_coma = raw;
}

float	Fixed::to_Float( void ) const {
    return ((double)_nbr_fixed_coma / (double(1 << _fractional_bits)));
}

int		Fixed::toInt( void ) const {
    return (_nbr_fixed_coma / (1 << _fractional_bits));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &tmp){
    out << tmp.to_Float();
    return (out);
}

Fixed::~Fixed(){
}
