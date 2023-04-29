//
// Created by Jonas Hermon-duc on 4/29/23.
//

#ifndef CPP_PISCINE_ARRAY_HPP
#define CPP_PISCINE_ARRAY_HPP
# include <string>
# include <exception>

template <typename T>
class Array
{
public:
    // Constructors
    Array() : _data(new T[0]), _size(0){};
    Array(unsigned int n) : _data(new T[n]), _size(n){};
    Array(const Array<T>& other): _data(new T[other._size]), _size(other._size){
        for(int i = 0; i < (int)_size; i++){
            this->_data[i] = other._data[i];
        }
    }

    // Destructor
    ~Array() {delete[] _data; }

    // Assignment operator
    Array<T>& operator=(const Array<T>& other);

    // Subscript operator
    T& operator[](unsigned int index);

    // Size function
    unsigned int size() const;

    // Printing functions
    void printArray() const;
    template <typename U>
    void printTypeArray() const;

private:
    T* _data;
    unsigned int _size;
};
#endif //CPP_PISCINE_ARRAY_HPP
