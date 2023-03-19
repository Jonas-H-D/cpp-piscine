//
// Created by Jonas Hermon-duc on 3/19/23.
//

#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "Default Frag constructor called" << std::endl;
    this->_name = "random";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

FragTrap::FragTrap(std::string str){
    std::cout << "Frag constructor // " << str << " // called" << std::endl;
    this->_name = str;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

FragTrap::FragTrap(const FragTrap &other){
    std::cout << "Copy Frag constructor called" << std::endl;
    *this = other;
}

FragTrap & FragTrap::operator=(const FragTrap & rhs){
    std::cout << "Frag: Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor :/ of: " <<  this->getName() << std::endl;
}

void	FragTrap::attack(const std::string &target){
    this->target = target;
    if (this->_hitPoints > 0 && this->_energyPoints > 0 ){
        std::cout << " /// FragTrap " << this->getName() << " attacks /// " << this->target << ", causing "<< this->_hitPoints << "  points of damage!"<< std::endl;
        this->_energyPoints -= 1;
    }
    else
        this->dead();
}

void FragTrap::dead(){
    std::cout << this->getName() <<": has no more Hit points and is **DEAD**" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << this->_name << " Please !!!! Give me a ++++ High 5 ++++ " << std::endl;
}