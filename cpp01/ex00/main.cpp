#include "Zombie.hpp"

int main(void)
{
	Zombie  patientZero = Zombie("Me");

	patientZero.announce();

	patientZero.randomChump("Peter");
	Zombie* farAway = patientZero.newZombie("Harald");
	farAway->announce();
	delete farAway;
}
