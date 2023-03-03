//
// Created by Jonas Hermon-Duc on 24/02/2023.
//

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string str) {
    setType(str);
}

Weapon::~Weapon() {
}

std::string const & Weapon::getType() const {
    return _type;
}

void    Weapon::setType(std::string value) {
    _type = value;
}

