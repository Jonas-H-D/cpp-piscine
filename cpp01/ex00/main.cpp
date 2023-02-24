#include "Zombie.hpp"

Zombie *newZombie(std::string name);

void	randomChump(std::string name);

int main(int argc, char** argv) {

    Zombie *zombie = newZombie("Jonas");
    zombie->announce();
    randomChump("Riri");
    delete zombie;
    return 0;
}