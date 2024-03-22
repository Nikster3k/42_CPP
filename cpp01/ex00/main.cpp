#include "Zombie.hpp"

int main(void)
{
	Zombie  patientZero = Zombie("Me");

	patientZero.announce();

	randomChump("Peter");
	Zombie* farAway = newZombie("Harald");
	farAway->announce();
	delete farAway;
}
