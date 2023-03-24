#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
    const AAnimal* animal[10];
//    const AAnimal test;

    for (int i = 0; i < 10; i++) {
        if (i % 2){
            animal[i] = new Dog();
        }
        else
            animal[i] = new Cat();
        animal[i]->makeSound();
    }

    const Dog* dogs[5];

    for (int i = 0; i < 5; i++) {
        dogs[i] = new Dog();
        dogs[i]->setIdea("I want to eat fingers", 0);
        std::cout << "++++++++++++++++++++" << dogs[i]->getIdea(0)  << std::endl;
    }

    std::cout << "\n-------Testing deep copy. creating a dog with brain and a copy to the dog-------\n" << std::endl;
    Dog	*chien = new Dog();
    Cat	*chat = new Cat();
    chien->setIdea("I like to snif stuff", 0);
    chien->setIdea("take over the world for more food", 99);
    chat->setIdea("I like to Miaaaaaaooooooo", 4);
    chat->setIdea("Humans are slaves ....", 22);
    std::cout << "chien idea 0 : " << chien->getIdea(0) << std::endl;
    std::cout << "chien idea 99 : " << chien->getIdea(99) << std::endl;
    std::cout << "chat idea 4: " << chat->getIdea(4) << std::endl;
    std::cout << "chat idea 22 : " << chat->getIdea(22) << std::endl;
    Dog	*copy_dog = new Dog(*chien);
    Cat	*copy_cat = new Cat(*chat);
    std::cout << "\n-------Deleting original dog. accessing ideas of the copy should not be segfault-------\n" << std::endl;
    delete chien;
    delete chat;
    std::cout << "\n-------original dog is deleted, printing ideas:-------\n" << std::endl;
    std::cout << "idea 0 : " << copy_dog->getIdea(0) << std::endl;
    std::cout << "idea 99 : " << copy_dog->getIdea(99) << std::endl;
    std::cout << "chat idea 4 : " << copy_cat->getIdea(4) << std::endl;
    std::cout << "chat idea 22 : " << copy_cat->getIdea(22) << std::endl;
    delete copy_dog;
    delete copy_cat;
    for (int i = 0; i < 5; i++) {
        delete dogs[i];
    }
    for (int i = 0; i < 10; i++) {
        delete animal[i];
    }

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    return 0;
}