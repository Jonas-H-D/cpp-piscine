#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(Span const &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span::~Span() {}

Span &Span::operator=(Span const &rhs){
    if (this == &rhs)
        return (*this);
    this->_maxSize = rhs._maxSize;
    this->_numbers = rhs._numbers;
    return *this;
}

void Span::addNumber(int num){
    if (_numbers.size() >= _maxSize) {
        throw NoSpaceLeftException();
    }
    _numbers.push_back(num);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}

int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw SpanNotFoundException();
    }

    std::vector<int> sortedNumbers(_numbers);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = INT_MAX;
    for(size_t i = 1; i < sortedNumbers.size(); ++i) {
        int diff = sortedNumbers[i] - sortedNumbers[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw SpanNotFoundException();
    }
    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());
    return maxElement - minElement;
}
