#pragma once
#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &src);

	Animal &operator=(const Animal &src);

	virtual ~Animal();
	virtual void makeSound() const = 0;

	std::string getType() const;
};