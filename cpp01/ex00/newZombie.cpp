#include "Zombie.hpp"

Zombie *newZombie(std::string name){
    Zombie *alloczombie;
    alloczombie = new Zombie(name);
    return (alloczombie);
}