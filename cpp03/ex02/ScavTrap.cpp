#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "ScavTrap Constructor has benn called for " << name << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor has benn called for " << name << std::endl;
}

void	ScavTrap::attack( const std::string& a_sTarget)
{
	if (hit_points <= 0 || energy_points <= 0)
		return ;
	std::cout << "ScavTrap " << name << " attacks " << a_sTarget << ", causing "
		<< attack_damage << " points of damage!" << std::endl;
	--energy_points;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
