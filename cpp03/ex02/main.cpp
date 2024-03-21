#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) 
{
	FragTrap trap("Peter");

	trap.attack("Evaluator");
	trap.attack("Enemy1");

	trap.takeDamage(4);
	trap.takeDamage(10);

	trap.beRepaired(2);
	trap.beRepaired(10);

	trap.takeDamage(4);
	trap.takeDamage(10);

	trap.highFivesGuys();

	trap.beRepaired(50);

	return 0;
}
