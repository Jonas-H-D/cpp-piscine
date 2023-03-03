//
// Created by Jonas Hermon-duc on 3/3/23.
//

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
public:
    HumanB();
    HumanB(std::string str);
    ~HumanB();
    Weapon *human_weapon;
    std::string name;
    void    attack();
    void    setWeapon(Weapon *weapon);
};

#endif
