#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <unistd.h>
#include <list>
#include <vector>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:

    MutantStack() {}
    MutantStack(const MutantStack &rhs) {
        this->c = rhs.c;
    }
    MutantStack& operator=(const MutantStack &rhs) {
        if (this != &rhs) {
            this->c = rhs.c;
        }
        return *this;
    }
    ~MutantStack() {}

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    const_iterator cbegin() const {
        return this->c.begin();
    }

    const_iterator cend() const {
        return this->c.end();
    }
};

#endif