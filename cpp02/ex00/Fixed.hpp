//
// Created by Jonas Hermon-duc on 3/11/23.
//

#ifndef CPP_PISCINE_FIXED_HPP
#define CPP_PISCINE_FIXED_HPP
#include <string>
#include <iostream>

class Fixed {
private:
    int _nbr_fixed_coma;
    static int const _fractional_bits = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    ~Fixed();
    Fixed & operator=(const Fixed &rhs);
    int getRawBits(void) const;
    void    setRawBits(int const raw);
};


#endif //CPP_PISCINE_FIXED_HPP
