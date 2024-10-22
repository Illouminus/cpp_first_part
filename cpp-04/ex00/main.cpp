#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl; 

    i->makeSound(); //  "Meow! Meow!"
    j->makeSound(); //  "Woof! Woof!"
    meta->makeSound(); // "Some generic animal sound."

    delete meta;
    delete j;
    delete i;

    const WrongAnimal* metaWrong = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();

    std::cout << k->getType() << " " << std::endl; // "WrongCat"

    k->makeSound(); // "Some wrong animal sound.", should be "WrongCat says: Meow!"

    delete metaWrong;
    delete k;

    return 0;
}
