#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string a_sName)
	: ClapTrap(a_sName + "_clap_name"), ScavTrap(a_sName), FragTrap(a_sName)
{
	DiamondTrap::name = a_sName;
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) 
	: ClapTrap(obj.name), ScavTrap(obj.name), FragTrap(obj.name)
{
	std::cout << "ClapTrap copy Constructor called!" << std::endl;
	DiamondTrap::name = obj.name;
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap&	DiamondTrap::operator= (const DiamondTrap& obj)
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

DiamondTrap::~DiamondTrap() 
{
	std::cout << "Destructor of the DIAMONDTRAP!!!" << std::endl;
}

void	DiamondTrap::attack(const std::string& a_sTarget)
{
	ScavTrap::attack(a_sTarget);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
