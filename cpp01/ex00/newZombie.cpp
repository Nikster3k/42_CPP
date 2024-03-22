#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie*	heapzombie = new Zombie(name);
	return (heapzombie);
}