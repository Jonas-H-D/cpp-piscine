#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    Animal	catCopy = *cat;
    Dog 	dogCopy(*dog);

    std::cout << "Type: " << meta->getType() << std::endl;
    std::cout << "Type: " << cat->getType() << std::endl;
    std::cout << "Type: " << catCopy.getType() << std::endl;
    std::cout << "Type: " << dog->getType() << std::endl;
    std::cout << "Type: " << dogCopy.getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
    meta->makeSound();
    dog->makeSound();
    dogCopy.makeSound();

    delete meta;
    delete dog;
    delete cat;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    const WrongCat 	wrongCatCopy(*wrongCat);

    std::cout << "Type: " << wrongMeta->getType() << " " << std::endl;
    std::cout << "Type: " << wrongCat->getType() << " " << std::endl;
    std::cout << "Type: " << wrongCatCopy.getType() << " " << std::endl;

    wrongCat->makeSound();
    wrongCatCopy.makeSound();

    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}