#include "Zombie.hpp"

int main() {
    Zombie *jonas = newZombie("Jonas");
    jonas->announce();
    randomChump("Riri");
    delete jonas;
    return 0;
}