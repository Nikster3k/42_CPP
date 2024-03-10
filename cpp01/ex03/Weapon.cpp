#include "Weapon.hpp"

Weapon::Weapon(std::string a_sType) 
{
	type = a_sType;
}

Weapon::~Weapon(void) {}

std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string a_sNewType)
{
	type = a_sNewType;
}