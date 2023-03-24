//
// Created by Jonas Hermon-duc on 3/20/23.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
protected:
    std::string _type;
public:
    Animal();
    Animal(std::string type);
    Animal(Animal const &other);
    Animal& operator=(Animal const &rhs);
    virtual ~Animal();

    std::string    getType() const;
    virtual void    makeSound() const;

};



#endif
