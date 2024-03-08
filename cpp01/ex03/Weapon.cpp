#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::~Weapon(void) {}

std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}