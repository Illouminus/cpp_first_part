#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
	std::string name;
	AMateria *inventory[4];
	int equipped;

  public:
	Character();
	Character(std::string const &name);
	Character(Character const &other);

	Character &operator=(Character const &other);

	~Character();

	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

	void printInventory() const;
};