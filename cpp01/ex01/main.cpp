#include "Zombie.hpp"

int main(void)
{
	Zombie	patientZero = Zombie("Me");

	patientZero.announce();

	Zombie*	horde = zombieHorde(10, "Hordie");
	for (int i = 0; i < 10; i++)
		horde[i].announce();

	delete[] horde;
}
