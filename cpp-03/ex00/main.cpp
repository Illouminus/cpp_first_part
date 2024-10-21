#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Creating ClapTrap Objects ===" << std::endl;
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");
	ClapTrap c("Charlie");
	ClapTrap const d(b);
	ClapTrap e;
	e = a;

	std::cout << "\n=== Initial States ===" << std::endl;
	std::cout << "a: " << a.getName() << " | HP: " << a.getHitPoints()
				 << " | EP: " << a.getEnergyPoints() << " | AD: " << a.getAttackDamage() << std::endl;
	std::cout << "b: " << b.getName() << " | HP: " << b.getHitPoints()
				 << " | EP: " << b.getEnergyPoints() << " | AD: " << b.getAttackDamage() << std::endl;
	std::cout << "c: " << c.getName() << " | HP: " << c.getHitPoints()
				 << " | EP: " << c.getEnergyPoints() << " | AD: " << c.getAttackDamage() << std::endl;
	std::cout << "d: " << d.getName() << " | HP: " << d.getHitPoints()
				 << " | EP: " << d.getEnergyPoints() << " | AD: " << d.getAttackDamage() << std::endl;
	std::cout << "e: " << e.getName() << " | HP: " << e.getHitPoints()
				 << " | EP: " << e.getEnergyPoints() << " | AD: " << e.getAttackDamage() << std::endl;

	std::cout << "\n=== Actions ===" << std::endl;

	std::cout << "\n--- Alpha Attacks Bravo ---" << std::endl;
	a.attack("Bravo");
	b.takeDamage(a.getAttackDamage());

	std::cout << "\n--- Bravo Repairs Itself ---" << std::endl;
	b.beRepaired(5);

	std::cout << "\n--- Charlie Attacks Alpha ---" << std::endl;
	c.attack("Alpha");
	a.takeDamage(c.getAttackDamage());

	std::cout << "\n--- Alpha Repairs Itself ---" << std::endl;
	a.beRepaired(3);

	std::cout << "\n--- Bravo Attacks Charlie ---" << std::endl;
	b.attack("Charlie");
	c.takeDamage(b.getAttackDamage());

	std::cout << "\n--- Attempting to Attack with No Energy ---" << std::endl;
	ClapTrap lowEnergy("LowEnergy");
	for (int i = 0; i < 10; ++i)
	{
		lowEnergy.attack("Target");
	}
	lowEnergy.attack("Target");

	std::cout << "\n=== Final States ===" << std::endl;
	std::cout << "a: " << a.getName() << " | HP: " << a.getHitPoints()
				 << " | EP: " << a.getEnergyPoints() << " | AD: " << a.getAttackDamage() << std::endl;
	std::cout << "b: " << b.getName() << " | HP: " << b.getHitPoints()
				 << " | EP: " << b.getEnergyPoints() << " | AD: " << b.getAttackDamage() << std::endl;
	std::cout << "c: " << c.getName() << " | HP: " << c.getHitPoints()
				 << " | EP: " << c.getEnergyPoints() << " | AD: " << c.getAttackDamage() << std::endl;
	std::cout << "d: " << d.getName() << " | HP: " << d.getHitPoints()
				 << " | EP: " << d.getEnergyPoints() << " | AD: " << d.getAttackDamage() << std::endl;
	std::cout << "e: " << e.getName() << " | HP: " << e.getHitPoints()
				 << " | EP: " << e.getEnergyPoints() << " | AD: " << e.getAttackDamage() << std::endl;

	return (0);
}