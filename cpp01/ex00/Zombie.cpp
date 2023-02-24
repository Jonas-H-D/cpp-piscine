//
// Created by Jonas Hermon-Duc on 24/02/2023.
//

#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " is destroyed" << std::endl;
}

void    Zombie::announce( void ){
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name){
    return (new Zombie(name));
}

void    randomChump(std::string name){
    Zombie  otherZombie = Zombie(name);
    otherZombie.announce();
}

