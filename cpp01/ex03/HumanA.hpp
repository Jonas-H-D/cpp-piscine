#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
public:
    HumanA();
    HumanA(std::string str, Weapon &weapon);
    ~HumanA();
    std::string name;
    Weapon      &human_weapon;
    void attack();
};

#endif