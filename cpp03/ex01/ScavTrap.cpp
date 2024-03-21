#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "ScavTrap Constructor called for " << name << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj.name)
{
	std::cout << "ScavTrap copy Constructor called!" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap&	ScavTrap::operator= (const ScavTrap& obj)
{
	if (this != &obj)
	{
		name = obj.name;
		attack_damage = obj.attack_damage;
		hit_points = obj.hit_points;
		energy_points = obj.energy_points;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for " << name << std::endl;
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
