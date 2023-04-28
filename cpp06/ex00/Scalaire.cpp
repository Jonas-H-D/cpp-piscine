//
// Created by Jonas Hermon-duc on 4/15/23.
//
#include "Scalaire.hpp"

Scalar::Scalar(const std::string& string)
        : _string(string)
{
    if (string.empty())
        throw Scalar::InputException();
    else if (string.size() == 1)
    {
        if (isdigit(string[0]))
        {
            this->_intVal = static_cast<int>(atoi(string.c_str()));
            this->_type = intType;
        }
        else
        {
            this->_charVal = string[0];
            this->_type = charType;
        }
    }
    else
    {
        char *longChar;
        long longConvert = strtol(string.c_str(), &longChar, 10);
        char *doubleChar;
        double doubleConvert = strtof(string.c_str(), &doubleChar);
        if (*longChar)
        {
            if (*doubleChar)
            {
                if (*doubleChar == 'f')
                {
                    this->_floatVal = static_cast<float>(doubleConvert);
                    this->_type = floatType;
                }
                else
                    throw Scalar::InputException();
            }
            else
            {
                this->_doubleVal = doubleConvert;
                this->_type = doubleType;
            }
        }
        else
        {
            if (longConvert > std::numeric_limits<int>::max() || longConvert < std::numeric_limits<int>::min())
                throw Scalar::InputException();
            else
            {
                this->_intVal = static_cast<int>(longConvert);
                this->_type = intType;
            }
        }
    }
}

Scalar::~Scalar()
{
}

char Scalar::toChar() const
{
    switch (this->_type)
    {
        char c;
        case charType:
            return this->_charVal;
        case intType:
            c = static_cast<char>(this->_intVal);
            if (!isprint(c))
                throw Scalar::NonDisplayable();
            else
                return c;
        case floatType:
            c = static_cast<char>(this->_floatVal);
            if (isnan(this->_floatVal) || isinf(this->_floatVal)
                || this->_floatVal > std::numeric_limits<char>::max() || this->_floatVal < std::numeric_limits<char>::min())
                throw Scalar::Impossible();
            else if (!isprint(c))
                throw Scalar::NonDisplayable();
            else
                return c;
        case doubleType:
            c = static_cast<char>(this->_doubleVal);
            if (isnan(this->_doubleVal) || isinf(this->_doubleVal)
                || this->_doubleVal > std::numeric_limits<char>::max() || this->_doubleVal < std::numeric_limits<char>::min())
                throw Scalar::Impossible();
            else if (!isprint(c))
                throw Scalar::NonDisplayable();
            else
                return c;
        default:
            break;
    }
}

int Scalar::toInt() const
{
    switch (this->_type)
    {
        case charType:
            return static_cast<int>(this->_charVal);
        case intType:
            return this->_intVal;
        case floatType:
            if (isnan(this->_floatVal) || isinf(this->_floatVal)
                || this->_floatVal > std::numeric_limits<int>::max() || this->_floatVal < std::numeric_limits<int>::min())
                throw Scalar::Impossible();
            else
                return static_cast<int>(this->_floatVal);
        case doubleType:
            if (isnan(this->_doubleVal) || isinf(this->_doubleVal)
                || this->_doubleVal > std::numeric_limits<int>::max() || this->_doubleVal < std::numeric_limits<int>::min())
                throw Scalar::Impossible();
            else
                return static_cast<int>(this->_doubleVal);
        default:
            break;
    }
}

float Scalar::toFloat() const
{
    switch (this->_type)
    {
        case charType:
            return static_cast<float>(this->_charVal);
        case intType:
            return static_cast<float>(this->_intVal);
        case floatType:
            return this->_floatVal;
        case doubleType:
            return static_cast<float>(this->_doubleVal);
        default:
            break;
    }
}

double Scalar::toDouble() const
{
    switch (this->_type)
    {
        case charType:
            return static_cast<double>(this->_charVal);
        case intType:
            return static_cast<double>(this->_intVal);
        case floatType:
            return static_cast<double>(this->_floatVal);
        case doubleType:
            return this->_doubleVal;
        default:
            break;
    }
}

std::ostream& operator<<(std::ostream& out, const Scalar& rhs)
{
    out << "char: ";
    try
    {
        char c;
        c = rhs.toChar();
        out << "'" << c << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        out << e.what() << std::endl;
    }
    out << "int: ";
    try
    {
        int i;
        i = rhs.toInt();
        out << i << std::endl;
    }
    catch(const std::exception& e)
    {
        out << e.what() << std::endl;
    }
    out << "float: ";
    try
    {
        float f;
        f = rhs.toFloat();
        double intPart;
        if (modf(f, &intPart) == 0)
            out.precision(1);
        out << std::fixed << f << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        out << e.what() << std::endl;
    }
    out << "double: ";
    try
    {
        double d;
        d = rhs.toDouble();
        double intPart;
        if (modf(d, &intPart) == 0)
            out.precision(1);
        out << std::fixed << d << std::endl;
    }
    catch(const std::exception& e)
    {
        out << e.what() << std::endl;
    }
    return out;
}