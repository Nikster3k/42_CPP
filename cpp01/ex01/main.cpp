#include "Zombie.hpp"

int main(void)
{
	Zombie	patientZero = Zombie("Me");

	patientZero.announce();

	patientZero.randomChump("Peter");
	Zombie*	farAway = patientZero.newZombie("Harald");
	farAway->announce();

	Zombie*	horde = farAway->zombieHorde(10, "Hordie");
	for (int i = 0; i < 10; i++)
		horde[i].announce();

	delete[] horde;
	delete farAway;
}