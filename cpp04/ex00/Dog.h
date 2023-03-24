//
// Created by Jonas Hermon-duc on 3/20/23.
//

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
    Dog();
    Dog(Dog const &other);
    Dog(Animal const &other);
    Dog& operator=(Dog const &rhs);
    ~Dog();

    void    makeSound() const;
};

#endif
