#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string a_sName)
{
	std::cout << "Constructor has benn called!" << std::endl;
	name = a_sName;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor has benn called!" << std::endl;
}

void ClapTrap::attack(const std::string & a_sTarget)
{
	if (hit_points <= 0 || energy_points <= 0)
		return ;
	std::cout << "ClapTrap " << name << " attacks " << a_sTarget << ", causing "
		<< attack_damage << " points of damage!" << std::endl;
	--energy_points;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount
		<< " points of damage! Now at " << hit_points << " hitpoints!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points <= 0 || energy_points <= 0)
		return ;
	hit_points += amount;
	std::cout << "ClapTrap " << name << " repairs health by " << amount
		<< " hitpoints! Now at " << hit_points << "!" << std::endl;
	--energy_points;
}
