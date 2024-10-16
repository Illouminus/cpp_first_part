#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon club("crude spiked club");
	Weapon sword("fine steel sword");

	HumanA jim("Jim", club);
	jim.attack();

	HumanB bob("Bob");
	bob.attack();

	bob.setWeapon(sword);
	bob.attack();

	club.setType("shiny gold club");
	sword.setType("rusty iron sword");

	jim.attack();
	bob.attack();

	return 0;
}