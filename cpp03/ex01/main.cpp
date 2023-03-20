#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

    ScavTrap    amanda("Amanda");
    ScavTrap    pedro("Pedro");

    amanda.beRepaired(10);
    amanda.attack("SkyFall");
    pedro.takeDamage(10);
    amanda.guardGate();
    pedro.takeDamage(100);


    return 0;
}