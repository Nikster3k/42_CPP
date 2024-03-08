#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(Weapon& weapon)
{
	this->weapon = weapon;
}

HumanA::~HumanA() {}

void	HumanA::attack(void)
{
	std::cout << name << "attacks with their " << weapon.getType() << std::endl;
}