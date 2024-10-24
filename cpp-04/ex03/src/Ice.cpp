#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>


Ice::Ice() : AMateria("ice")
{
   //std::cout << "Ice constructor" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    //std::cout << "Ice copy constructor" << std::endl;
}

Ice &Ice::operator=(Ice const &other)
{
    if(this != &other)
        AMateria::operator=(other);
    // std::cout << "Ice assigned.\n";
    return *this;
}

Ice::~Ice()
{
    //std::cout << "Ice destructor" << std::endl;
}

AMateria *Ice::clone() const 
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << " * shoots an ice bolt at " << target.getName() << std::endl;
}