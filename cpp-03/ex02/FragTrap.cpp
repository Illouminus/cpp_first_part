#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default_frag")
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap(void) constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap(\"" << name << "\") constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called for " << obj.name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destroyed" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
	{
		ClapTrap::operator=(obj); // Вызов оператора присваивания базового класса
		std::cout << "FragTrap copy assignment operator called for " << obj.name << std::endl;
	}
	return (*this);
}

void FragTrap::attack(std::string const &target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is destroyed and cannot attack!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "FragTrap " << name << " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	this->energyPoints -= 1;
	std::cout << "FragTrap " << name << " attacks " << target
				 << ", causing " << attackDamage << " points of damage! "
				 << "Remaining EP: " << energyPoints << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " is destroyed and cannot request a high five!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " requests a high five! ✋" << std::endl;
}