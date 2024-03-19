#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(void)
{
	std::cout << name << " destroyed!" << std::endl;;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie*	heapzombie = new Zombie();
	heapzombie->name = name;
	return (heapzombie);
}

Zombie*	Zombie::zombieHorde(int N, std::string name)
{
	Zombie*	zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].name = name;
	return (zombies);    
}

void	Zombie::randomChump(std::string name)
{
	Zombie	rando = Zombie();
	rando.name = name;
	rando.announce();
}
