//
// Created by Jonas Hermon-Duc on 24/02/2023.
//

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
    std::string _type;
public:
    Weapon();
    Weapon(std::string str);
    ~Weapon();
    std::string const & getType() const;
    void setType(std::string value);
};

#endif
