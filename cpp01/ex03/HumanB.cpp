#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( Weapon* weapon = NULL)
{
	this->weapon = weapon;
}

HumanB::~HumanB() {}

void	HumanB::attack(void)
{
	if (weapon == NULL)
		return ;
	std::cout << name << "attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon wep)
{
	weapon = wep;
}