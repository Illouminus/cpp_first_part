#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>



Cure::Cure() : AMateria("cure")
{
    //std::cout << "Cure constructor" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
    //std::cout << "Cure copy constructor" << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
    if(this != &src)
        AMateria::operator=(src);
    // std::cout << "Cure assigned.\n";
    return *this;
}


Cure::~Cure()
{
    //std::cout << "Cure destructor" << std::endl;
}

AMateria *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << " * heals " << target.getName() << "'s wounds" << std::endl;
}