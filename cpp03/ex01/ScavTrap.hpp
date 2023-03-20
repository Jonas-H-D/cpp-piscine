//
// Created by Jonas Hermon-duc on 3/19/23.
//

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ~ScavTrap();

    ScavTrap & operator=(const ScavTrap & rhs);

    void	attack(const std::string &target);
    void    guardGate();
    void    dead();
};


#endif
