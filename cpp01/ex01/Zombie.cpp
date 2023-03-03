//
// Created by Jonas Hermon-Duc on 24/02/2023.
//

#include "Zombie.hpp"

Zombie::Zombie()
{
    _name = "Balthazar";
}

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " is destroyed" << std::endl;
}

void    Zombie::announce( void ) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
