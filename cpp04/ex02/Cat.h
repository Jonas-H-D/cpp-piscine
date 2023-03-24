//
// Created by Jonas Hermon-duc on 3/20/23.
//

#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public AAnimal {
private:
    Brain *_brain;
public:
    Cat();
    Cat(Cat const &other);
    Cat& operator=(Cat const &rhs);
    ~Cat();

    virtual void    makeSound() const;
    std::string   getIdea(int i) const;
    void    setIdea(std::string text, int i) const;
};

#endif
