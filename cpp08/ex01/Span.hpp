//
// Created by Jonas Hermon-Duc on 05/05/2023.
//

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <ctime>
#include <unistd.h>

class Span {
public:
    Span(unsigned int N);
    Span(Span const &other);
    Span& operator=(Span const &rhs);
    ~Span();

    void addNumber(int num);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;

    class NoSpaceLeftException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return ("Error: maximal capacity reached");
        }
    };

    class SpanNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return ("Error: Span not found, need more values");
        }
    };

private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
};

#endif //SPAN_HPP
