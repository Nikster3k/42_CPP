#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) 
{
	ScavTrap trap("Peter");

	trap.attack("Evaluator");
	trap.attack("Enemy1");

	trap.takeDamage(4);
	trap.takeDamage(10);

	trap.beRepaired(2);
	trap.beRepaired(10);

	trap.takeDamage(4);
	trap.takeDamage(10);

	trap.guardGate();

	trap.beRepaired(10);

	return 0;
}
