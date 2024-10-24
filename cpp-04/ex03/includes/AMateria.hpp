#pragma once
#include <iostream>


class ICharacter;

class AMateria
{
  protected:
	std::string type;

  public:
	AMateria(std::string const &type);
	AMateria(AMateria const &other);

	AMateria &operator=(AMateria const &other);
	
	virtual ~AMateria();

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};