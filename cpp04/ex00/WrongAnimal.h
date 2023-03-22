//
// Created by Jonas Hermon-Duc on 21/03/2023.
//

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

# include <string.h>
# include <iostream>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const &other);
    WrongAnimal& operator=(WrongAnimal const &rhs);
    ~WrongAnimal();

    std::string    getType() const;
    void    makeSound() const;

};


#endif
