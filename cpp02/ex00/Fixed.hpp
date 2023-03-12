#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>

class Fixed{
private:
    int _fix_nbr;
    int const static _bits_nbr = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed & operator=(const Fixed &rhs);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif