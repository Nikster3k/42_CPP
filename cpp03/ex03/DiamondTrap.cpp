#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string a_sName)
	: ClapTrap(a_sName + "_clap_name"), ScavTrap(a_sName), FragTrap(a_sName)
{
	name = a_sName;
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap() 
{
	std::cout << "Destructor of the DIAMONDTRAP!!!" << std::endl;
}

void	DiamondTrap::attack(const std::string& a_sTarget)
{
	ScavTrap::attack(a_sTarget);
}
