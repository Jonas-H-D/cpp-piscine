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
    Array() : _data(new T[0]), _size(0){}
    Array(unsigned int n) : _data(new T[n]), _size(n) {
        for (unsigned int i = 0; i < n; i++) {
            _data[i] = 0;
        }
    }
    Array(const Array<T>& other): _data(new T[other._size]), _size(other._size){
        for(int i = 0; i < (int)_size; i++){
            this->_data[i] = other._data[i];
        }
    }

    // Destructor
    ~Array() {delete[] _data; }

    // Assignment operator
    Array<T>& operator=(const Array<T>& other){
        if (this != &other){
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++){
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Subscript operator
    T& operator[](unsigned int i) const {
        if (i >= _size) {
            throw OutOfRange();
        }
        return _data[i];
    }

    class OutOfRange : public std::exception {
    public:
        virtual const char* what() const throw() { return "Index is out of array range";}
    };

    // Size function
    unsigned int size() const{
        return _size;
    }
private:

    T* _data;
    unsigned int _size;
};

template < typename T >
void printObjectFunction(Array<T> &tab, unsigned int size){
    std::cout << "Array Printing" << std::endl;
    for(int i=0; i < size; i++){
        std::cout << tab[i] << " ";
    }
}

template < typename T > void printTypeFunction(T& tab, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
        std::cout << tab[i] << " ";
}

#endif //CPP_PISCINE_ARRAY_HPP
