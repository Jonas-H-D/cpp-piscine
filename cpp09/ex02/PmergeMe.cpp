//
// Created by Jonas Hermon-Duc on 25/05/2023.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **stack){
    int value;
    int i = 1;

    while (i != argc && is_digit(stack[i])) {
        value = std::atoi(stack[i]);
        _myDeque.push_back(value);
        _myVector.push_back(value);
        std::cout << value << ' ';
        i++;
    }
    std::cout << std::endl;
    sortAndPrint();
}

PmergeMe::PmergeMe(const PmergeMe &rhs) {
    _myDeque.clear();
    _myVector.clear();

    _myDeque.insert(_myDeque.begin(), rhs._myDeque.begin(), rhs._myDeque.end());
    _myVector.insert(_myVector.begin(), rhs._myVector.begin(), rhs._myVector.end());

    sortAndPrint();
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _myDeque.clear();
        _myVector.clear();

        _myDeque.insert(_myDeque.begin(), other._myDeque.begin(), other._myDeque.end());
        _myVector.insert(_myVector.begin(), other._myVector.begin(), other._myVector.end());

        sortAndPrint();
    }
    return *this;
}

bool PmergeMe::is_digit(const std::string str) {
    for (int i = 0; i < (int)str.size(); i++){
        if (!isdigit(str[i])){
            std::cerr << "Error: non digit value" << std::endl;
            exit(0);
        }
    }
    return true;
}

void PmergeMe::mergePrint(std::string str) {
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
    mergePrint("Before sort");
    std::clock_t start = std::clock();
    merge_sort(_myDeque);
    _myDeque.assign(_myDeque.begin(), std::unique(_myDeque.begin(), _myDeque.end()));
    std::clock_t end = std::clock();
    double temps = double(end - start) / CLOCKS_PER_SEC;
    mergePrint("After sort");
    std::cout << "Time to process with std::deque: " << temps * 1000000<< "ms."<< std::endl;

    start = std::clock();
    merge_sort(_myVector);
    _myVector.assign(_myVector.begin(), std::unique(_myVector.begin(), _myVector.end()));
    end = std::clock();
    double duration = (end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process with std::vector: " << temps * 1000000<< "ms."<< std::endl;
    std::cout << "**************** ********* ********** **************" << temps * 1000000<< "ms."<< std::endl;
}


