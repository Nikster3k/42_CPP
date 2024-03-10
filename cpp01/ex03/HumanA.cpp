#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string a_sName, Weapon& a_cWeapon) : weapon(a_cWeapon)
{
	this->name = a_sName;
}

HumanA::~HumanA() {}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}