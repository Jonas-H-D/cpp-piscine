//
// Created by Jonas Hermon-Duc on 25/05/2023.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **input){
    int value;
    int i = 1;

    while (input[i] && is_digit(input[i])) {
        value = std::atoi(input[i]);
        _myDeque.push_back(value);
        _myVector.push_back(value);
        //std::cout << value << ' ';
        i++;
    }
    size = i - 1;
    //std::cout << std::endl;
    sortAndPrint();
}

PmergeMe::PmergeMe(const PmergeMe &rhs) {
    _myDeque.clear();
    _myVector.clear();

    _myDeque.insert(_myDeque.begin(), rhs._myDeque.begin(), rhs._myDeque.end());
    _myVector.insert(_myVector.begin(), rhs._myVector.begin(), rhs._myVector.end());
    size = rhs.size;
    sortAndPrint();
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _myDeque.clear();
        _myVector.clear();

        _myDeque.insert(_myDeque.begin(), other._myDeque.begin(), other._myDeque.end());
        _myVector.insert(_myVector.begin(), other._myVector.begin(), other._myVector.end());

        size = other.size;
        sortAndPrint();
    }
    return *this;
}

bool PmergeMe::is_digit(const std::string str) {
    for (int i = 0; i < (int)str.size(); i++){
        if (!isdigit(str[i])){
            std::cerr << "Error" << std::endl;
            exit(0);
        }
    }
    return true;
}

void PmergeMe::listPrint(std::string str) {
    std::deque<int>::iterator it = _myDeque.begin();
    std::cout << str << ": ";
    while (it != _myDeque.end() && std::distance(_myDeque.begin(), it) < 4) {
        std::cout << *it++ << ' ';
    }
    if (_myDeque.size() == 5)
        std::cout << *it;
    else if(_myDeque.size() > 5)
    std::cout << "[...]";
    std::cout << std::endl;
}

void PmergeMe::sortAndPrint() {
    listPrint("Before sort");

    std::clock_t start = std::clock();
    merge_sort(_myDeque);
    _myDeque.assign(_myDeque.begin(), std::unique(_myDeque.begin(), _myDeque.end()));
    std::clock_t end = std::clock();
    double temps = double(end - start) / CLOCKS_PER_SEC;

    listPrint("After sort");

    std::cout << "Time to process a range of " << size <<" elements with std::deque : " << temps * 1000000<< "ms."<< std::endl;

    std::clock_t debut = std::clock();
    merge_sort(_myVector);
    _myVector.assign(_myVector.begin(), std::unique(_myVector.begin(), _myVector.end()));
    std::clock_t fin = std::clock();
    double duration = double(fin - debut) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << size <<" elements with std::vector : " << duration * 1000000<< "ms."<< std::endl;
    std::cout << "**************** ********* ********** **************" << std::endl;
}

/*std::vector stores its elements in a contiguous block of memory, allowing for efficient random access and cache locality.
This contiguous
memory layout often leads to better performance for sorting algorithms*/
