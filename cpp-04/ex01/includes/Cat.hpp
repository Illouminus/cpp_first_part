#pragma once
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const std::string type);
	Cat(const Cat &src);

	Cat &operator=(const Cat &src);

	~Cat();

	void makeSound() const;
};