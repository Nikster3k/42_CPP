#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "FragTrap Constructor has benn called for " << name << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor has benn called for " << name << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "This is a positive high five request from " << name << " FragTrap" << std::endl;
}
