#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "FragTrap Constructor has benn called for " << name << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj.name)
{
	std::cout << "FragTrap copy Constructor called!" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap&	FragTrap::operator= (const FragTrap& obj)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor has benn called for " << name << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "This is a positive high five request from " << name << " FragTrap" << std::endl;
}
