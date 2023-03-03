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
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void    announce( void );
};

void    randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif //ZOMBIE_HPP
