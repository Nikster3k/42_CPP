#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) 
{
	DiamondTrap	trap("Peter");

	trap.whoAmI();

	// for (size_t i = 0; i < 100; i++)
	// {
	// 	std::cout << "[ " << i + 1 << " ] ";
	// 	trap.attack("Evaluator");
	// }
	
	trap.attack("Evaluator");
	trap.attack("Enemy1");

	trap.takeDamage(4);
	trap.takeDamage(10);

	trap.beRepaired(2);
	trap.beRepaired(10);

	trap.takeDamage(4);
	trap.takeDamage(10);

	trap.highFivesGuys();
	trap.guardGate();

	trap.beRepaired(500);
	trap.beRepaired(1000);

	return 0;
}
