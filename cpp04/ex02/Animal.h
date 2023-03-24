//
// Created by Jonas Hermon-duc on 3/20/23.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class AAnimal {
protected:
    std::string _type;
public:
    virtual ~AAnimal();

    virtual void    makeSound() const = 0;

};

#endif
