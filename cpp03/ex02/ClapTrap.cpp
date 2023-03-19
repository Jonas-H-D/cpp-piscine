//
// Created by Jonas Hermon-duc on 3/19/23.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    this->setName("Default Trap");
    std::cout << "ClapTrap constructor Default created :?" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    this->setName(name);
    std::cout << "ClapTrap constructor" << name << " :)"<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor of " << this->getName() <<" called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    this->target = target;
    if (this->_hitPoints > 0 && this->_energyPoints > 0 ){
        std::cout << "ClapTrap " << this->getName() << " attacks " << this->target << ", causing "<< this->_hitPoints << "  points of damage!"<< std::endl;
        this->_energyPoints -= 1;
    }
    else
        this->dead();
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << this->getName() << " is attacked and is losing "<< this->_hitPoints << " energy points!"<< std::endl;
    this->_hitPoints -= amount;
    if (this->_hitPoints <= 0)
        this->dead();
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_energyPoints > 0 ){
        std::cout << "ClapTrap " << this->getName() << " is being Repaired of: " << amount << " points" << std::endl;
        this->_energyPoints -= 1;
        this->_hitPoints += amount;
    }
    else
        std::cout << "Not enough energy points to repair " << this->getName() << std::endl;
}

std::string ClapTrap::getName(){
    return this->_name;
}

void ClapTrap::setName(const std::string & name){
    this->_name = name;
}

void ClapTrap::dead(){
    std::cout << this->getName() <<": has no more Hit points and is **DEAD**" << std::endl;
//    this->alive = false;
}