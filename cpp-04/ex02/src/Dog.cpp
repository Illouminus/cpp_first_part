#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog constructed.\n";
}


Dog::Dog(const std::string name) : Animal(name), brain(new Brain())
{
	 std::cout << "Dog named " << name << " constructed.\n";
}

Dog::Dog(const Dog &src) : Animal(src), brain(new Brain(*src.brain))
{
	std::cout << "Dog copied.\n";
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructed.\n";
}

Dog& Dog::operator=(const Dog &src) {
    if (this != &src) 
        Animal::operator=(src);
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*src.brain);
    std::cout << "Dog assigned.\n";
    return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!\n";
}