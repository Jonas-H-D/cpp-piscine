//
// Created by Jonas Hermon-Duc on 25/05/2023.
//

#ifndef CPPPROJECTS_PMERGEME_HPP
#define CPPPROJECTS_PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>

#define PRINTABLE 10

class PmergeMe {
private:
    std::deque<int> _myDeque;
    std::vector<int> _myVector;
public:
    PmergeMe(int argc, char **stack);
    PmergeMe(const PmergeMe & rhs);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &other);

    bool is_digit(const std::string str);
    void sortAndPrint();
    void mergePrint(std::string str);
    int size;
};

template <typename T>
void    insertion_sort(T &container){
    typename T::iterator it = container.begin();
    typename T::iterator it2;

    while (it != container.end()){
        it2 = it;
        while (it2 != container.begin() && *it2 < *(it2 - 1)) {
            std::iter_swap(it2, it2 - 1);
            it2--;
        }
        it++;
    }
}

template <typename T>
void merge_sort(T &container){
    if (container.size() <= PRINTABLE){
        insertion_sort(container);
        return ;
    }
    typename T::iterator mid = container.begin() + container.size()/2;
    T left(container.begin(), mid);
    T right(mid, container.end());
    merge_sort(left);
    merge_sort(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
}
#endif //CPPPROJECTS_PMERGEME_HPP
