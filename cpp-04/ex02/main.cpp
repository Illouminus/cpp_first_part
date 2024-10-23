#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    Animal *animals[100];

    for(int i = 0; i < 100; i++)
    {
        if(i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for(int i = 0; i < 100; i++)
        animals[i]->makeSound();

    for(int i = 0; i < 100; i++)
        delete animals[i];

    return 0;
}
