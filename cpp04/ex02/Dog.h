//
// Created by Jonas Hermon-duc on 3/20/23.
//

#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public AAnimal {
private:
    Brain *_brain;
public:
    Dog();
    Dog(Dog const &other);
    Dog& operator=(Dog const &rhs);
    ~Dog();

    void    makeSound() const;
    std::string   getIdea(int i) const;
    void    setIdea(std::string text, int i) const;
};

#endif
