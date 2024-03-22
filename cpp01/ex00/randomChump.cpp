#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	rando = Zombie(name);
	rando.announce();
}
