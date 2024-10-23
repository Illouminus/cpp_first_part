#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(AMateria const &other) : type(other.type) {}