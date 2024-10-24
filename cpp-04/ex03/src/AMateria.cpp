#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) : type(type)
{
	//std::cout << "AMateria constructor" << std::endl;
}

AMateria::AMateria(AMateria const &other) : type(other.type)
{
	//std::cout << "AMateria copy constructor" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src)
	{
		this->type = src.type;
		//std::cout << "AMateria assigned.\n";
	}
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "AMateria destructor" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
	std::cout << " * uses " << type << " on " << target.getName() << std::endl;
}