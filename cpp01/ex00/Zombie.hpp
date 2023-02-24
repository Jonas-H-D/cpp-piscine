//
// Created by Jonas Hermon-Duc on 24/02/2023.
//

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;
public:
    Zombie(std::string name);
    ~Zombie();
    void    announce( void );
};

#endif //ZOMBIE_HPP
