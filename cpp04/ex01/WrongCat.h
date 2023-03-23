//
// Created by Jonas Hermon-Duc on 21/03/2023.
//

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat &other);
    WrongCat(const WrongAnimal &other);
    WrongCat& operator=(WrongCat const &rhs);
    ~WrongCat();

    void    makeSound() const;
};


#endif
