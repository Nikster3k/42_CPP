#include <iostream>
#include "ClapTrap.hpp"

int main( void ) 
{
	ClapTrap	trap("Peter");

	trap.attack("Evaluator");
	trap.takeDamage(4);
	trap.beRepaired(2);	
	trap.takeDamage(4);	
	trap.takeDamage(4);	
	trap.takeDamage(4);
	trap.takeDamage(4);
	trap.takeDamage(4);
	trap.takeDamage(4);
	trap.takeDamage(4);
	trap.beRepaired(500);
	trap.beRepaired(500);
	trap.beRepaired(500);
}
