#pragma once
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const std::string type);
	Cat(const Cat &src);

	Cat &operator=(const Cat &src);

	~Cat();

	void makeSound() const override;
};