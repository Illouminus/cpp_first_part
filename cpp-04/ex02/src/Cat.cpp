#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    std::cout << "Cat constructed.\n";
}

Cat::Cat(const std::string name) : Animal(name), brain(new Brain())
{
    std::cout << "Cat named " << name << " constructed.\n";
}

Cat::Cat(const Cat &src) : Animal(src), brain(new Brain(*src.brain))
{
    std::cout << "Cat copied.\n";
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructed.\n";
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
        Animal::operator=(src);
    if(this->brain)
        delete this->brain;
    this->brain = new Brain(*src.brain);
    std::cout << "Cat assigned.\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow!\n";
}