#include "includes/Dog.hpp";
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructed.\n";
}
