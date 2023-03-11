//
// Created by Jonas Hermon-duc on 3/11/23.
//

#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <cmath>
#include <iostream>

class Fixed {
private:
    int _nbr_fixed_coma;
    static int const _fractional_bits = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int num);
    Fixed(const float num);
    ~Fixed();

    Fixed & operator=(const Fixed &rhs);

    bool	operator>(const Fixed & rhs) const;
    bool	operator<(const Fixed & rhs) const;
    bool	operator>=(const Fixed & rhs) const;
    bool	operator<=(const Fixed & rhs) const;
    bool	operator==(const Fixed & rhs) const;
    bool	operator!=(const Fixed & rhs) const;

    Fixed	operator+(const Fixed & rhs) const;
    Fixed	operator-(const Fixed & rhs) const;
    Fixed	operator*(const Fixed & rhs) const;
    Fixed	operator/(const Fixed & rhs) const;

    Fixed	operator++(int);
    Fixed	&operator++(void);
    Fixed	operator--(int);
    Fixed	&operator--(void);

    static Fixed		&min(Fixed &a, Fixed &b);
    static Fixed const	&min(const Fixed &a, const Fixed &b);
    static Fixed		&max(Fixed &a, Fixed &b);
    static Fixed const	&max(const Fixed &a, const Fixed &b);

    int getRawBits(void) const;
    void    setRawBits(int const raw);
    float	to_Float( void ) const;
    int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &tmp);

#endif
