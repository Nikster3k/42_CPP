#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "undefined";
	std::cout << "ClapTrap default Constructor called for " << name << std::endl;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(std::string a_sName)
{
	std::cout << "ClapTrap Constructor called for " << a_sName << std::endl;
	name = a_sName;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "Copy Constructor called!" << std::endl;
	name = obj.name;
	hit_points = obj.hit_points;
	energy_points = obj.energy_points;
	attack_damage = obj.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj) {
		name = obj.name;
		hit_points = obj.hit_points;
		energy_points = obj.energy_points;
		attack_damage = obj.attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string & a_sTarget)
{
	if (hit_points <= 0 || energy_points <= 0)
		return ;
	std::cout << "ClapTrap " << name << " attacks " << a_sTarget << ", causing "
		<< attack_damage << " points of damage!" << std::endl;
	--energy_points;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points = hit_points - static_cast<int>(amount) < 0 ? 0 : hit_points - amount;
 	std::cout << "ClapTrap " << name << " takes " << amount
		<< " points of damage! Now at " << hit_points << " hitpoints!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points <= 0 || energy_points <= 0)
		return ;
	hit_points += amount;
	std::cout << "ClapTrap " << name << " repairs health by " << amount
		<< " hitpoints! Now at " << hit_points << "!" << std::endl;
	--energy_points;
}
