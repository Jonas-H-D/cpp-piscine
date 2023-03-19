//
// Created by Jonas Hermon-duc on 3/19/23.
//

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap {
protected:
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
    std::string _name;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const &other);
    ClapTrap& operator=(ClapTrap const &rhs);
    ~ClapTrap();
    std::string target;

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName();
    void setName(const std::string & name);
    void dead();
};

#endif
