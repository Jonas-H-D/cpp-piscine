//
// Created by Jonas Hermon-duc on 3/19/23.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "Default Scav constructor called" << std::endl;
    this->_name = "random";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string str){
    std::cout << "Scav constructor // " << str << " // called" << std::endl;
    this->_name = str;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other){
    std::cout << "Copy Scav constructor called" << std::endl;
    *this = other;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs){
    std::cout << "Scav: Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor :/ of: " <<  this->getName() << std::endl;
}

void	ScavTrap::attack(const std::string &target){
    this->target = target;
    if (this->_hitPoints > 0 && this->_energyPoints > 0 ){
        std::cout << " /// ScavTrap " << this->getName() << " attacks /// " << this->target << ", causing "<< this->_hitPoints << "  points of damage!"<< std::endl;
        this->_energyPoints -= 1;
    }
    else
        this->dead();
}

void ScavTrap::dead(){
    std::cout << this->getName() <<": has no more Hit points and is **DEAD**" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << this->_name << " Is now in *** Gate Keeper *** mode " << std::endl;
}
