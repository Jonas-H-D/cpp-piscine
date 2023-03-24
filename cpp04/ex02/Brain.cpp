//
// Created by Jonas Hermon-Duc on 22/03/2023.
//

#include "Brain.h"

Brain::Brain() {
    std::cout << "xxxxxx  Brain Constructor xxxxxx" << std::endl;
}

Brain::Brain(Brain const &other){
    std::cout << "Brain copy Constructor" << std::endl;
    *this = other;
}

Brain& Brain::operator=(Brain const &rhs){
    std::cout << "Brain copy Constructor" << std::endl;
    if (this == &rhs)
        return (*this);
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain Destructor" << std::endl;
}