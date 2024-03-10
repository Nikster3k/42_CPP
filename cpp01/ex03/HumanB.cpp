#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name)
{
	this->weapon = NULL;
	this->name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack(void)
{
	if (weapon == NULL)
		return ;
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& wep)
{
	weapon = &wep;
}