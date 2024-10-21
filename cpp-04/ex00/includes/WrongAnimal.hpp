#pragma once
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &src);

	WrongAnimal operator=(const WrongAnimal &src);

	~WrongAnimal();

	void makeSound() const;
};