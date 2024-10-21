#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap(void) constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap(\"" << name << "\") constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	*this = obj;
	std::cout << "ClapTrap copy constructor called " << obj.name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " is destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	std::cout << "ClapTrap copy assignment operator called " << obj.name << std::endl;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << name << " attacks " << target
				 << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already destroyed and cannot take more damage!" << std::endl;
		return;
	}
	if (amount >= this->hitPoints)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is destroyed and cannot be repaired!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy points left and cannot be repaired!" << std::endl;
		return;
	}
	this->energyPoints -= 1;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << name << " is repaired for " << amount
				 << " hit points! Current hit points: " << hitPoints << std::endl;
}

std::string ClapTrap::getName() const
{
	return name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}