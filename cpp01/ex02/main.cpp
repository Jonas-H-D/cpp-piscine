#include <iostream>
#include <string>

//Créez un programme comportant :
//• Une variable de type string initialisée à "HI THIS IS BRAIN".
//• stringPTR : Un pointeur sur la string.
//• stringREF : Une référence sur la string.
//Votre programme doit afficher :
//• L’adresse de la string en mémoire.
//• L’adresse stockée dans stringPTR.
//• L’adresse stockée dans stringREF.
//Puis :
//• La valeur de la string.
//• La valeur pointée par stringPTR.
//• La valeur pointée par stringREF.

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* brainPTR = &brain;
    std::string& brainREF = brain;

    std::cout << "adresse de la string en mémoire: " << &brainPTR << std::endl;
    std::cout << "adresse stockée dans stringPTR: " << brainPTR << std::endl;
    std::cout << "adresse stockée dans stringREF: " << &brainREF << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "La valeur de la string: " << brain << std::endl;
    std::cout << "La valeur pointée par stringPTR: " << *brainPTR << std::endl;
    std::cout << "La valeur pointée par stringREF: " << brainREF << std::endl;
    return 0;
}