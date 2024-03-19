#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) 
{
	DiamondTrap	trap("Gigachad");

	trap.attack("Evaluator");
	trap.attack("Enemy1");
	trap.attack("Enemy2");
	trap.attack("Enemy3");

	trap.takeDamage(4);
	trap.takeDamage(10);
	trap.takeDamage(20);
	trap.takeDamage(30);

	trap.beRepaired(2);
	trap.beRepaired(10);
	trap.beRepaired(50);
	trap.beRepaired(100);

	trap.takeDamage(4);
	trap.takeDamage(10);
	trap.takeDamage(20);
	trap.takeDamage(30);

	trap.highFiveGuys();
	trap.guardGate();

	trap.beRepaired(500);
	trap.beRepaired(1000);
	trap.beRepaired(2000);
	trap.beRepaired(3000);

	return 0;
}
