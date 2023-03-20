#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
    std::cout << " ==========       CONSTRUCTOR      ========== "<< std::endl << std::endl;

    ScavTrap    scav("riri");
    FragTrap	frag("Fifi");

    std::cout << std::endl;

    std::cout << "==========       ACTION !!!       ==========" << std::endl << std::endl;

    scav.attack("Mathew Fraser");
    scav.takeDamage(99);
    scav.beRepaired(150);
    std::cout << std::endl;
    scav.guardGate();
    std::cout << std::endl;
    scav.takeDamage(789);
    scav.beRepaired(150);
    std::cout << std::endl;

    std::cout << " = = = = = = = = = = = = = = = = = = = = =" << std::endl << std::endl;

    frag.attack("Rich Froning");
    frag.takeDamage(99);
    frag.beRepaired(150);
    std::cout << std::endl;
    frag.highFivesGuys();
    std::cout << std::endl;
    frag.takeDamage(789);
    frag.beRepaired(150);
    std::cout << std::endl;

    std::cout << "==========       DESTRUCTOR       ==========" << std::endl << std::endl;

    return 0;
}