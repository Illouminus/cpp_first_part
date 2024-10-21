#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Создание объектов ClapTrap ===" << std::endl;
	ClapTrap clap1("Clappy");
	ClapTrap clap2("ClappyClone");
	ClapTrap clap3;
	clap3 = clap1; // Присваивание

	std::cout << "\n=== Создание объектов ScavTrap ===" << std::endl;
	ScavTrap scav1("Scavvy");
	ScavTrap scav2("ScavvyClone");
	ScavTrap scav3;
	scav3 = scav1; // Присваивание

	std::cout << "\n=== Начальные состояния ===" << std::endl;

	// Вывод состояния ClapTrap объектов
	std::cout << "ClapTrap 1: " << clap1.getName()
				 << " | HP: " << clap1.getHitPoints()
				 << " | EP: " << clap1.getEnergyPoints()
				 << " | AD: " << clap1.getAttackDamage() << std::endl;

	std::cout << "ClapTrap 2: " << clap2.getName()
				 << " | HP: " << clap2.getHitPoints()
				 << " | EP: " << clap2.getEnergyPoints()
				 << " | AD: " << clap2.getAttackDamage() << std::endl;

	std::cout << "ClapTrap 3: " << clap3.getName()
				 << " | HP: " << clap3.getHitPoints()
				 << " | EP: " << clap3.getEnergyPoints()
				 << " | AD: " << clap3.getAttackDamage() << std::endl;

	// Вывод состояния ScavTrap объектов
	std::cout << "ScavTrap 1: " << scav1.getName()
				 << " | HP: " << scav1.getHitPoints()
				 << " | EP: " << scav1.getEnergyPoints()
				 << " | AD: " << scav1.getAttackDamage() << std::endl;

	std::cout << "ScavTrap 2: " << scav2.getName()
				 << " | HP: " << scav2.getHitPoints()
				 << " | EP: " << scav2.getEnergyPoints()
				 << " | AD: " << scav2.getAttackDamage() << std::endl;

	std::cout << "ScavTrap 3: " << scav3.getName()
				 << " | HP: " << scav3.getHitPoints()
				 << " | EP: " << scav3.getEnergyPoints()
				 << " | AD: " << scav3.getAttackDamage() << std::endl;

	std::cout << "\n=== Действия ===" << std::endl;

	// Действия с ClapTrap
	std::cout << "\n--- ClapTrap 1 атакует ScavTrap 1 ---" << std::endl;
	clap1.attack("Scavvy");
	scav1.takeDamage(clap1.getAttackDamage());

	std::cout << "\n--- ClapTrap 1 ремонтирует себя ---" << std::endl;
	clap1.beRepaired(5);

	// Действия с ScavTrap
	std::cout << "\n--- ScavTrap 1 атакует ClapTrap 1 ---" << std::endl;
	scav1.attack("Clappy");
	clap1.takeDamage(scav1.getAttackDamage());

	std::cout << "\n--- ScavTrap 1 входит в режим охранника ворот ---" << std::endl;
	scav1.guardGate();

	// Тестирование исчерпания энергии ScavTrap
	std::cout << "\n--- ScavTrap 1 атакует множество раз для исчерпания энергии ---" << std::endl;
	for (int i = 0; i < 51; ++i) // EP = 50
	{
		scav1.attack("DummyTarget");
	}

	// Попытка ремонта с исчерпанной энергией
	std::cout << "\n--- ScavTrap 1 пытается отремонтироваться с исчерпанной энергией ---" << std::endl;
	scav1.beRepaired(10);

	// Тестирование уничтожения ClapTrap
	std::cout << "\n--- ClapTrap 2 получает фатальный урон ---" << std::endl;
	clap2.takeDamage(100); // Уничтожение ClapTrap 2

	std::cout << "\n--- ClapTrap 2 пытается атаковать после уничтожения ---" << std::endl;
	clap2.attack("Scavvy");

	// ScavTrap атакует уничтоженного ClapTrap
	std::cout << "\n--- ScavTrap 2 атакует ClapTrap 3 ---" << std::endl;
	scav2.attack("ClappyClone");
	clap3.takeDamage(scav2.getAttackDamage());

	std::cout << "\n=== Финальные состояния ===" << std::endl;

	// Вывод финального состояния ClapTrap объектов
	std::cout << "ClapTrap 1: " << clap1.getName()
				 << " | HP: " << clap1.getHitPoints()
				 << " | EP: " << clap1.getEnergyPoints()
				 << " | AD: " << clap1.getAttackDamage() << std::endl;

	std::cout << "ClapTrap 2: " << clap2.getName()
				 << " | HP: " << clap2.getHitPoints()
				 << " | EP: " << clap2.getEnergyPoints()
				 << " | AD: " << clap2.getAttackDamage() << std::endl;

	std::cout << "ClapTrap 3: " << clap3.getName()
				 << " | HP: " << clap3.getHitPoints()
				 << " | EP: " << clap3.getEnergyPoints()
				 << " | AD: " << clap3.getAttackDamage() << std::endl;

	// Вывод финального состояния ScavTrap объектов
	std::cout << "ScavTrap 1: " << scav1.getName()
				 << " | HP: " << scav1.getHitPoints()
				 << " | EP: " << scav1.getEnergyPoints()
				 << " | AD: " << scav1.getAttackDamage() << std::endl;

	std::cout << "ScavTrap 2: " << scav2.getName()
				 << " | HP: " << scav2.getHitPoints()
				 << " | EP: " << scav2.getEnergyPoints()
				 << " | AD: " << scav2.getAttackDamage() << std::endl;

	std::cout << "ScavTrap 3: " << scav3.getName()
				 << " | HP: " << scav3.getHitPoints()
				 << " | EP: " << scav3.getEnergyPoints()
				 << " | AD: " << scav3.getAttackDamage() << std::endl;

	std::cout << "\n=== Завершение программы ===" << std::endl;

	return 0;
}