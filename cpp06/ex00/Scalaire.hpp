//
// Created by Jonas Hermon-duc on 4/15/23.
//

#ifndef CPP_PISCINE_SCALAIRE_HPP
#define CPP_PISCINE_SCALAIRE_HPP

#include <string>
#include <iostream>
#include <cmath>

class Scalar
{
private:
    const std::string&	_string;
    char				_charVal;
    int					_intVal;
    float				_floatVal;
    double				_doubleVal;
    enum {charType, intType, floatType, doubleType} _type;

public:
    Scalar(const std::string& string);
    Scalar& operator=(const Scalar& rhs);
    ~Scalar();

    char toChar() const;
    int toInt() const;
    float toFloat() const;
    double toDouble() const;

    class InputException : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return ("Invalid input");
        }
    };

    class Impossible : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return ("Impossible");
        }
    };

    class NonDisplayable : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return ("Non displayable");
        }
    };
};

std::ostream& operator<<(std::ostream& o, const Scalar& rhs);


#endif //CPP_PISCINE_SCALAIRE_HPP
