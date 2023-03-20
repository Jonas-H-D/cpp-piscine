//
// Created by Jonas Hermon-duc on 3/19/23.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    ~FragTrap();

    FragTrap & operator=(const FragTrap & rhs);

    void	attack(const std::string &target);
    void    highFivesGuys(void);
    void    dead();
};

#endif
