//
// Created by Jonas Hermon-duc on 3/20/23.
//

#ifndef CAT_H
#define CAT_H
#include "Animal.h"

class Cat : public Animal {
public:
    Cat();
    Cat(Cat const &other);
    Cat(Animal const &other);
    Cat& operator=(Cat const &rhs);
    ~Cat();

    void    makeSound() const;
};

#endif
