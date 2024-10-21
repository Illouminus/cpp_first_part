#pragma once
#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
public:
	Dog();
	Dog(const std::string name);
	Dog(const Dog &src);

	Dog operator=(const Dog &src);

	~Dog();

	void makeSound() const;
};